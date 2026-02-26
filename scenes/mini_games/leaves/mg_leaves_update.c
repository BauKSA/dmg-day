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

#include "../mg_mission_complete.h"
#include "../mg_player_movement.h"
#include "../mg_timer.h"

#include "./mg_leaves.h"

void check_actor_status() {
  for (uint8_t i = 0; i <= extra_actor_index; i++) {
    if (actor_active[i] == 0 && actor_state[i] == FALLING) {
      if ((my_rand() % 300) == 0) {
        actor_active[i] = 1;
        actor_timer[i] = 0;
        actor_y[i] = 24;

        continue;
      }

      continue;
    }

    if (actor_state[i] == FALLING)
      actor_y[i]++;

    if (actor_y[i] >= mg_leaves_DATA.bottom_limit && actor_state[i] == FALLING)
      actor_state[i] = ON_FLOOR;

    if (SWEEPING_FLAG) {
      uint8_t is_leaf;
      if (i < LEAF_COUNT)
        is_leaf = 1;
      else
        is_leaf = 0;

      if (actor_x[i] >= mg_leaves_DATA.right_limit &&
          actor_state[i] == BEING_SWEPT_RIGHT) {
        actor_state[i] = FALLING;
        actor_active[i] = 0;
        actor_y[i] = 0;

        seed = LY_REG;
        seed |= (unsigned int)DIV_REG << 8;

        uint8_t spawn_x = my_rand() % TOTAL_ACTORS;

        actor_x[i] = actor_spawn_x[spawn_x];
        if (is_leaf == 1)
          score += POSITIVE_SCORE;
        else
          score -= NEGATIVE_SCORE;
      } else if (actor_x[i] <= mg_leaves_DATA.left_limit &&
                 actor_state[i] == BEING_SWEPT_LEFT) {
        actor_state[i] = FALLING;
        actor_active[i] = 0;
        actor_y[i] = 0;

        seed = LY_REG;
        seed |= (unsigned int)DIV_REG << 8;

        uint8_t spawn_x = my_rand() % TOTAL_ACTORS;

        actor_x[i] = actor_spawn_x[spawn_x];
        actor_state[i] = FALLING;
        actor_active[i] = 0;
        actor_y[i] = 0;

        seed = LY_REG;
        seed |= (unsigned int)DIV_REG << 8;

        actor_x[i] = actor_spawn_x[spawn_x];
        if (is_leaf == 0)
          score += POSITIVE_SCORE;
        else
          score -= NEGATIVE_SCORE;
      }
    }

    if (actor_state[i] == BEING_SWEPT_RIGHT && SWEEPING_FLAG)
      actor_x[i] = position.x[mg_player] + 8;

    if (actor_state[i] == BEING_SWEPT_LEFT && SWEEPING_FLAG)
      actor_x[i] = position.x[mg_player] - 8;

    draw_extra(actor_ids[i], actor_x[i], actor_y[i], 1, 1);
  }
}

void check_actor_collision() {
  uint8_t x1 = position.x[mg_player];

  for (uint8_t i = 0; i < TOTAL_ACTORS; i++) {
    if (actor_state[i] == FALLING)
      continue;

    uint8_t x2 = actor_x[i];

    if (x1 < x2 + 8 && x1 + 4 > x2) {
      if (x1 > x2)
        actor_state[i] = BEING_SWEPT_LEFT;

      if (x2 > x1)
        actor_state[i] = BEING_SWEPT_RIGHT;
    } else {
      actor_state[i] = ON_FLOOR;
    }
  }
}

void Mg_Leaves_Update(Scene *scene) {
  Mg_TimerUpdate();

  if (mgt_alarm == 1) {
    Mg_TimerStopAlarm();

    for (int8_t i = 0; i < extra_actor_index; i++)
      draw_extra(i, 0, -1, 1, 1);

    position.y[mg_player] = 0;
    draw_actor(mg_player);

    Mg_SplashCompleteScreen();

    scene_manager->change_scene(MAP_00, &player);
    return;
  }

  if (keys & J_A)
    SWEEPING_FLAG = 1;
  else
    SWEEPING_FLAG = 0;

  Mg_PlayerMovement(1, 0);

  check_actor_status();
  check_actor_collision();

  draw_actor(mg_player);

  if (score != score_cache) {
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
