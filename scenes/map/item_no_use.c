#include "item_no_use.h"

#include "../../include/language.h"
#include "../../include/text_positions.h"
#include "../../include/char_to_tile.h"
#include "../../assets/chars/chars.h"

#include <gb/gb.h>
#include <stdint.h>

void ItemNoUseText()
{
    if (language == ENGLISH)
    {
        char text[] = "can't use";
        char text2[] = "that here...";

        for (uint8_t i = 0; text[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(text[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y, tile);
        }

        for (uint8_t i = 0; text2[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(text2[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y + 1, tile);
        }
    }
    else
    {
        char text[] = "esto no me";
        char text2[] = "sirve ahora...";

        for (uint8_t i = 0; text[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(text[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y, tile);
        }

        for (uint8_t i = 0; text2[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(text2[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y + 1, tile);
        }
    }
}