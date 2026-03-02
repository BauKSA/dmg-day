#include "../../assets/chars/chars.h"
#include "../../include/all_scenes.h"
#include "../../include/char_to_tile.h"
#include "../../include/player.h"
#include "../../include/scene_manager.h"
#include "./story.h"

#include <gb/gb.h>

void Story_Update(Scene *scene) {
  if (story_lines_timer < story_lines_rate) {
    story_lines_timer++;
    return;
  }

  if (actual_story_line >= story_lines_count) {
    scene_manager.change_scene(MAP_00, &player);
    return;
  }

  if (story_lines[actual_story_line][actual_line_char] == '\n') {
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
