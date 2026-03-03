#include "../../../assets/chars/chars.h"
#include "../../../include//inventory.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/position.h"
#include "../../../include/text_positions.h"
#include "./map_00.h"
#include <stdint.h>

void Map_00_CheckItems()
{
  if (active_item == ITM_NONE)
    return;

  if (actual_tile.value == 0)
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

    active_item = ITM_NONE;
}
