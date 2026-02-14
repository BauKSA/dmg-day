#include <gb/gb.h>
#include "./map_data.h"

const uint8_t empty_tile = 150;

void clean()
{
    CurrentMapData.event_active = 0;
    set_bkg_tiles(15, 1, 1, 1, &empty_tile);
    set_bkg_tiles(17, 1, 1, 1, &empty_tile);

    for (size_t i = 1; i <= 18; i++)
    {
        set_bkg_tiles(i, 15, 1, 1, &empty_tile);
        set_bkg_tiles(i, 16, 1, 1, &empty_tile);
    }
}