#include <gb/gb.h>
#include <stdlib.h>

#include "./mini_games.h"
#include "../../include/char_to_tile.h"
#include "../../include/text_positions.h"
#include "../../assets/chars/chars.h"

void Mg_SetTitle(char title[MAX_SIZE_MG_TITLE])
{
    for (uint8_t i = 0; title[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(title[i]) + CHARS_TILESET_START;
        set_bkg_tiles(NAME_START_X + i, NAME_START_Y, 1, 1, &tile);
    }
}