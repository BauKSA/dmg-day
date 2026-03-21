#pragma bank 5

#include "../../assets/sprites/backgrounds/template/template.h"
#include "../../assets/sprites/frames/text_frame.h"
#include "./story.h"

#include "../../include/language.h"

#include <gb/gb.h>

void Story_Init(Scene *scene, Entity player)
{
  set_bkg_data(0, template_tileset_size, template_tileset);
  set_bkg_tiles(0, 0, 20, 18, template_tilemap);

  TextFrame_Init(14, 7);

  if (language == SPANISH)
  {
    char *line_1 = "hoy sale la nueva";
    char *line_2 = "game boy! me voy a";
    char *line_3 = "ratear del colegio";
    char *line_4 = "a ver si consigo";
    char *line_5 = "plata y la puedo";
    char *line_6 = "comprar";

    story_lines_count = 3;

    for (uint8_t i = 0; line_1[i] != '\0'; i++)
    {
      story_lines[0][i] = line_1[i];
    }

    for (uint8_t i = 0; line_2[i] != '\0'; i++)
    {
      story_lines[1][i] = line_2[i];
    }

    for (uint8_t i = 0; line_3[i] != '\0'; i++)
    {
      story_lines[2][i] = line_3[i];
    }

    for (uint8_t i = 0; line_4[i] != '\0'; i++)
    {
      story_lines[3][i] = line_4[i];
    }

    for (uint8_t i = 0; line_5[i] != '\0'; i++)
    {
      story_lines[4][i] = line_5[i];
    }

    for (uint8_t i = 0; line_6[i] != '\0'; i++)
    {
      story_lines[5][i] = line_6[i];
    }

    story_lines_count = 6;
  }
  else
  {
    char *line_1 = "new game boy is";
    char *line_2 = "out today! i will";
    char *line_3 = "skip school and";
    char *line_4 = "try to get some";
    char *line_5 = "money so i can";
    char *line_6 = "buy it";

    story_lines_count = 6;

    for (uint8_t i = 0; line_1[i] != '\0'; i++)
    {
      story_lines[0][i] = line_1[i];
    }
    for (uint8_t i = 0; line_2[i] != '\0'; i++)
    {
      story_lines[1][i] = line_2[i];
    }
    for (uint8_t i = 0; line_3[i] != '\0'; i++)
    {
      story_lines[2][i] = line_3[i];
    }
    for (uint8_t i = 0; line_4[i] != '\0'; i++)
    {
      story_lines[3][i] = line_4[i];
    }
    for (uint8_t i = 0; line_5[i] != '\0'; i++)
    {
      story_lines[4][i] = line_5[i];
    }
    for (uint8_t i = 0; line_6[i] != '\0'; i++)
    {
      story_lines[5][i] = line_6[i];
    }
  }
}
