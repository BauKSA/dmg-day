#include "../../assets/sprites/backgrounds/template/template.h"
#include "../../assets/sprites/frames/text_frame.h"
#include "./story.h"

#include <gb/gb.h>

void Story_Init(Scene *scene, Entity player) {
  set_bkg_data(0, template_tileset_size, template_tileset);
  set_bkg_tiles(0, 0, 20, 18, template_tilemap);

  TextFrame_Init(14, 7);

  char line_1[12] = "aca contamos";
  char line_2[12] = "la historia";
  char line_3[12] = "de dmg day.";

  story_lines_count = 3;

  for (uint8_t i = 0; line_1[i] != '\0'; i++) {
    story_lines[0][i] = line_1[i];
  }

  for (uint8_t i = 0; line_2[i] != '\0'; i++) {
    story_lines[1][i] = line_2[i];
  }

  for (uint8_t i = 0; line_3[i] != '\0'; i++) {
    story_lines[2][i] = line_3[i];
  }
}
