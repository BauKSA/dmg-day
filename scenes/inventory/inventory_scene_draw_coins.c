#pragma bank 5

#include "inventory_scene.h"

#include <gb/gb.h>
#include <stdint.h>

#include "../../assets/chars/numbers.h"
#include "../../include/money.h"

void InventoryScene_DrawCoins()
{
    uint8_t digitos[5];

    for (uint8_t i = 5; i >= 1; i--)
    {
        digitos[i - 1] = money % 10;
        money /= 10;
    }

    uint8_t x = 9;
    uint8_t y = 12;

    for (uint8_t i = 0; i < 5; i++)
    {
        uint8_t tile = digitos[i] + NUMBER_TILESET_START;
        set_bkg_tile_xy(x + i, y, tile);
    }
}