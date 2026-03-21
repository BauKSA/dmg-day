#pragma bank 7

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
        story_lines[0] = "hoy sale la nueva";
        story_lines[1] = "game boy! me voy a";
        story_lines[2] = "ratear del colegio";
        story_lines[3] = "a ver si consigo";
        story_lines[4] = "plata y la puedo";
        story_lines[5] = "comprar";
    }
    else
    {
        story_lines[0] = "new game boy is";
        story_lines[1] = "out today! i will";
        story_lines[2] = "bunk off school"; 
        story_lines[3] = "and try to get";
        story_lines[4] = "some money so i";
        story_lines[5] = "can buy it";
    }
    
    story_lines_count = 6;
    ended = 0;
    actual_story_line = 0;
    actual_line_char = 0;
}