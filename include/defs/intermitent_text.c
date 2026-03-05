#include "../intermitent_text.h"
#include "../../assets/chars/chars.h"
#include "../char_to_tile.h"
#include <gb/gb.h>

void IntermitentText_Init(uint8_t x_start, uint8_t y, char *text, uint8_t rate)
{
    uint8_t it_timer = 0;
    uint8_t it_rate = rate;

    for (uint8_t i = 0; text[i] != '\0'; i++)
    {
        while (it_timer < it_rate)
        {
            vsync();
            it_timer++;
            continue;
        }
        it_timer = 0;

        uint8_t char_tile = char_to_tile(text[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(x_start + i, y, char_tile);
    }
}