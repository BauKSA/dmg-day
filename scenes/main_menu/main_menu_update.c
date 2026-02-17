#include <gb/gb.h>
#include "./main_menu.h"
#include "../../include/scene.h"
#include "../../include/char_to_tile.h"
#include "../../assets/chars/chars.h"

void MainMenu_Update(Scene *scene)
{
    timer++;
    MainMenu_CheckInput();

    if (timer >= rate)
    {
        timer = 0;

        if (show_text == 1)
        {
            show_text = 0;

            uint8_t empty_tile = 255;
            for (size_t i = 4; i < 16; i++)
            {
                set_bkg_tiles(i, 9, 1, 1, &empty_tile);
            }
        }
        else
        {
            show_text = 1;

            const char text[] = "press  start";
            uint8_t x = 4;

            for (size_t i = 0; i < 12; i++)
            {
                uint8_t tile = char_to_tile(text[i]) + CHARS_TILESET_START;
                set_bkg_tiles(x, 9, 1, 1, &tile);
                x++;
            }
        }
    }
}