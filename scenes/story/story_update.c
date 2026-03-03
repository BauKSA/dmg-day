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
    keys = 0;
    uint8_t visible = 0;
    story_lines_rate = 30;
    story_lines_timer = 0;

    while (1)
    {
      vsync();
      keys = joypad();

      uint8_t button = BUTTON_TILESET_START + 1;
      uint8_t empty_tile = 255;

      if (keys & J_A)
        break;

      if (story_lines_timer < story_lines_rate)
      {
        story_lines_timer++;
        continue;
      }

      story_lines_timer = 0;

      if (visible == 1)
      {
        set_bkg_tile_xy(17, 11, empty_tile);
        visible = 0;
      }
      else
      {
        set_bkg_tile_xy(17, 11, button);
        visible = 1;
      }
    }

    scene_manager.change_scene(MAP_00, &player);
    return;
  }

  if (story_lines_timer < story_lines_rate)
  {
    story_lines_timer++;
    return;
  }

  if (actual_story_line >= story_lines_count)
  {
    ended = 1;
    return;
  }

  if (story_lines[actual_story_line][actual_line_char] == '\0' || actual_line_char >= 12)
  {
    actual_story_line++;
    actual_line_char = 0;

    return;
  }

  story_lines_timer = 0;

  uint8_t x = 3;
  uint8_t y = 4;

  uint8_t tile =
      char_to_tile(story_lines[actual_story_line][actual_line_char]) +
      CHARS_TILESET_START;

  set_bkg_tile_xy(x + actual_line_char, y + actual_story_line, tile);

  actual_line_char++;
}
