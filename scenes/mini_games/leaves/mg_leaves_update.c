#pragma bank 2

#include <gb/gb.h>

#include "../../../assets/chars/numbers.h"
#include "../../../include/all_scenes.h"
#include "../../../include/draw.h"
#include "../../../include/extra_actor.h"
#include "../../../include/input.h"
#include "../../../include/player.h"
#include "../../../include/random.h"
#include "../../../include/scene_manager.h"
#include "../../../include/text_positions.h"
#include "../../../include/can_move.h"

#include "../mg_mission_complete.h"
#include "../mg_player_movement.h"
#include "../mg_timer.h"

#include "./mg_leaves.h"

uint8_t is_being_swept(uint8_t actor_idx)
{
  uint8_t x1 = position.x[mg_player];

  uint8_t x2 = actor_x[actor_idx];

  if (x1 < x2 + 8 && x1 + 4 > x2)
  {
    if (x1 > x2)
      actor_state[actor_idx] = BEING_SWEPT_LEFT;

    if (x2 > x1)
      actor_state[actor_idx] = BEING_SWEPT_RIGHT;

    return 1;
  }

  return 0;
}

void spawn(uint8_t actor_idx)
{
  if (actor_state[actor_idx] == INACTIVE)
    actor_timer[actor_idx]++;

  if (actor_state[actor_idx] == INACTIVE && my_rand() % (45 + actor_idx * 15) == 0)
  {
    actor_timer[actor_idx] = 0;
    actor_state[actor_idx] = FALLING;
    actor_active[actor_idx] = 1;

    actor_y[actor_idx] = 40;
    fixed_y[actor_idx] = 40 << 8;

    actor_x[actor_idx] = available_x[next_spawn_idx];
    next_spawn_idx = (next_spawn_idx + 1) % TOTAL_ACTORS;
  }
}

void check_actor_status()
{
  for (uint8_t i = 0; i < TOTAL_ACTORS; i++)
  {
    uint8_t is_leaf = (i < LEAF_COUNT);

    spawn(i);

    if (actor_state[i] == FALLING)
    {
      uint8_t speed = 255;
      if (is_leaf)
        speed = 176;

      fixed_y[i] += speed;
      actor_y[i] = fixed_y[i] >> 8;
    }

    if (SWEEPING_FLAG)
    {
      if (actor_state[i] == BEING_SWEPT_LEFT)
        actor_x[i] = position.x[mg_player] - 8;
      else if (actor_state[i] == BEING_SWEPT_RIGHT)
        actor_x[i] = position.x[mg_player] + 8;
    }

    draw_extra(actor_ids[i], actor_x[i], actor_y[i], 1, 1);
  }
}

void check_actor_collision()
{
  for (uint8_t i = 0; i < TOTAL_ACTORS; i++)
  {
    if (!actor_active[i] || actor_state[i] == INACTIVE)
      continue;

    if (actor_state[i] == FALLING)
    {
      if (actor_y[i] >= mg_leaves_DATA.bottom_limit)
      {
        actor_state[i] = ON_FLOOR;
        actor_y[i] = mg_leaves_DATA.bottom_limit;
      }
      else
        continue;
    }

    if (is_being_swept(i) == 0)
      actor_state[i] = ON_FLOOR;

    uint8_t is_leaf = (i < LEAF_COUNT);

    if (actor_state[i] == BEING_SWEPT_LEFT && actor_x[i] <= mg_leaves_DATA.left_limit)
    {
      actor_state[i] = INACTIVE;
      actor_active[i] = 0;

      actor_y[i] = 0;
      fixed_y[i] = 0;

      if (is_leaf)
        score -= NEGATIVE_SCORE;
      else
        score += POSITIVE_SCORE;
    }

    if (actor_state[i] == BEING_SWEPT_RIGHT && actor_x[i] >= mg_leaves_DATA.right_limit)
    {
      actor_state[i] = INACTIVE;
      actor_active[i] = 0;

      actor_y[i] = 0;
      fixed_y[i] = 0;

      if (is_leaf)
        score += POSITIVE_SCORE;
      else
        score -= NEGATIVE_SCORE;
    }
  }
}

void Mg_Leaves_Update(Scene *scene)
{
  Mg_TimerUpdate();

  if (mgt_alarm == 1)
  {
    Mg_TimerStopAlarm();

    for (int8_t i = 0; i < extra_actor_index; i++)
      draw_extra(i, 0, -1, 1, 1);

    position.y[mg_player] = 0;
    draw_actor(mg_player);

    Mg_SplashCompleteScreen();
    Mg_CompleteScreenSleep();

    scene_manager.change_scene(MAP_00, &player);
    return;
  }

  if (keys & J_A)
    SWEEPING_FLAG = 1;
  else
    SWEEPING_FLAG = 0;

  if (position.x[mg_player] <= mg_leaves_DATA.left_limit - 4)
    can_move.left = 0;
  else
    can_move.left = 1;

  if (position.x[mg_player] >= mg_leaves_DATA.right_limit + 4)
    can_move.right = 0;
  else
    can_move.right = 1;

  Mg_PlayerMovement(1, 0);

  check_actor_status();
  check_actor_collision();

  draw_actor(mg_player);

  if (score != score_cache)
  {
    score_cache = score;

    uint8_t thousands = ((score / 1000) % 10) + NUMBER_TILESET_START;
    uint8_t hundreds = ((score / 100) % 10) + NUMBER_TILESET_START;
    uint8_t tens = ((score / 10) % 10) + NUMBER_TILESET_START;
    uint8_t units = (score % 10) + NUMBER_TILESET_START;

    set_bkg_tile_xy(TEXT_START_X + 6 + 0, TEXT_START_Y, thousands);
    set_bkg_tile_xy(TEXT_START_X + 6 + 1, TEXT_START_Y, hundreds);
    set_bkg_tile_xy(TEXT_START_X + 6 + 2, TEXT_START_Y, tens);
    set_bkg_tile_xy(TEXT_START_X + 6 + 3, TEXT_START_Y, units);
  }

  uint16_t seconds = mgt_current_frame / 60;

  uint8_t t_tens = (seconds / 10) + NUMBER_TILESET_START;
  uint8_t t_units = (seconds % 10) + NUMBER_TILESET_START;

  set_bkg_tile_xy(TEXT_START_X + 6, TEXT_START_Y + 1, t_tens);
  set_bkg_tile_xy(TEXT_START_X + 6 + 1, TEXT_START_Y + 1, t_units);

  return;
}
