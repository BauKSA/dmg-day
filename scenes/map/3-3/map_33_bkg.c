#pragma bank 5
#include <gb/gb.h>

#include "../../../assets/sprites/backgrounds/maps/3-3/map_3-3.h"

void Map_33_LoadBKG()
{
    set_bkg_data(0, map_3_3_tileset_size, map_3_3_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_3_3_tilemap);
}