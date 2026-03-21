#pragma bank 7

#include "../../assets/chars/chars.h"
#include "../../assets/chars/buttons.h"
#include "../../include/all_scenes.h"
#include "../../include/char_to_tile.h"
#include "../../include/player.h"
#include "../../include/scene_manager.h"
#include "../../include/input.h"
#include "./story.h"

#include <gb/gb.h>

void Story_Update(Scene *scene)
{
  if (ended == 1)
  {
    story_lines_timer++;
    if (story_lines_timer >= story_lines_rate)
    {
      story_lines_timer = 0;
      static uint8_t visible = 0;
      visible = !visible;
      set_bkg_tile_xy(17, 11, visible ? (BUTTON_TILESET_START + 1) : 255);
    }

    if (joypad() & J_A)
    {
      scene_manager.change_scene(MAP_21, &player);
    }
    return;
  }

  uint8_t x_start = 2;
  uint8_t y_start = 5;

  for (uint8_t i = 0; i < story_lines_count; i++)
  {
    uint8_t j = 0;
    while (story_lines[i][j] != '\0')
    {
      uint8_t tile = char_to_tile(story_lines[i][j]) + CHARS_TILESET_START;
      set_bkg_tile_xy(x_start + j, y_start + i, tile);
      j++;
    }
  }

  ended = 1;
  story_lines_timer = 0;
}