#pragma bank 6

#include <gb/gb.h>
#include <stdint.h>

#include "../mg_mission_complete.h"
#include "../mg_set_coins_reward.h"
#include "mg_homework.h"

#include "../../../include/input.h"
#include "../../../include/intermitent_text.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/scene_manager.h"

#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/backgrounds/minigames/homework/correct_icons.h"

void Mgh_clean()
{
  uint8_t empty_tile = 255;

  for (uint8_t i = 0; i < 13; i++)
  {
    set_bkg_tile_xy(QUESTION_X + i, QUESTION_Y, empty_tile);
    if (i < 10)
      set_bkg_tile_xy(OPTION_X + i, OPTION_Y, empty_tile);
  }

  for (uint8_t i = 1; i < 4; i++)
  {
    for (uint8_t j = 0; j < 13; j++)
    {
      set_bkg_tile_xy(QUESTION_X + j, QUESTION_Y + i, row_tile);

      if (j < 10)
        set_bkg_tile_xy(OPTION_X + j, OPTION_Y + i, row_tile);
    }
  }
}

void Mg_Homework_Update(Scene *scene)
{
  uint8_t questions_left = 6;

  while (questions_left > 0)
  {
    uint8_t timer = 0;

    uint8_t tens = ((QUESTION_TIME - timer) / 10) + NUMBER_TILESET_START;
    uint8_t units = ((QUESTION_TIME - timer) % 10) + NUMBER_TILESET_START;

    set_bkg_tile_xy(9, 16, tens);
    set_bkg_tile_xy(10, 16, units);

    uint8_t qi = QUESTION_COUNT - questions_left;
    for (uint8_t i = 0; i < test[qi].question.lines_count; i++)
    {
      IntermitentText_Init(QUESTION_X, QUESTION_Y + i,
                           test[qi].question.lines_txt[i], 5);
    }

    for (uint8_t i = 0; i < test[qi].options_count; i++)
    {
      IntermitentText_Init(OPTION_X, OPTION_Y + i, test[qi].options[i].txt, 5);
    }

    uint16_t s = 0;
    uint8_t correct_answer = 0;

    keys = 0;
    prev_keys = 0;

    while (s < QUESTION_TIME * 60)
    {

      prev_keys = keys;
      keys = joypad();

      if ((keys & J_UP) && !(prev_keys & J_UP))
      {
        if (test[qi].options[0].correct == 0)
          break;

        correct_answer = 1;
        break;
      }

      if ((keys & J_LEFT) && !(prev_keys & J_LEFT))
      {
        if (test[qi].options[1].correct == 0)
          break;

        correct_answer = 1;
        break;
      }

      if ((keys & J_RIGHT) && !(prev_keys & J_RIGHT) &&
          test[qi].options_count > 2)
      {
        if (test[qi].options[2].correct == 0)
          break;

        correct_answer = 1;
        break;
      }

      if ((keys & J_DOWN) && !(prev_keys & J_DOWN) &&
          test[qi].options_count > 3)
      {
        if (test[qi].options[3].correct == 0)
          break;

        correct_answer = 1;
        break;
      }

      if (s % 60 == 0)
      {
        timer++;

        tens = ((QUESTION_TIME - timer) / 10) + NUMBER_TILESET_START;
        units = ((QUESTION_TIME - timer) % 10) + NUMBER_TILESET_START;

        set_bkg_tile_xy(9, 16, tens);
        set_bkg_tile_xy(10, 16, units);
      }

      vsync();

      s++;
    }

    questions_left--;

    Mgh_clean();

    uint8_t tile = HOMEWORK_ICONS_TILESET_START + 1;
    if (correct_answer == 0)
      tile++;
    else
      correct_answers++;

    uint8_t y = 15;
    if (qi > 2)
      y++;

    uint8_t x = 14 + (qi % 3);

    set_bkg_tile_xy(x, y, tile);

    for (uint8_t s = 0; s < 60; s++)
      vsync();
  }

  Mgh_clean();

  uint8_t success = 0;
  if (correct_answers >= correct_goal)
    success = 1;

  uint16_t reward = Mg_SetCoinsReward((uint8_t)NPC_TAREA, success);

  Mg_SplashCompleteScreen((uint8_t)NPC_TAREA, success, reward);
  Mg_CompleteScreenSleep();

  uint8_t humor = humor_stats[(uint8_t)NPC_TAREA];

  if (success == 1 && humor < 2)
    humor++;
  if (success == 0 && humor > 0)
    humor--;

  humor_stats[(uint8_t)NPC_TAREA] = humor;

  next_scene = prev_scene;
  return;
}
