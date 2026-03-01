#include <gb/gb.h>
#include "./mg_leaves.h"
#include "../../../assets/sprites/backgrounds/minigames/leaves/bkg_leaves_example.h"

void Mg_Leaves_LoadBKG()
{
    set_bkg_data(0, bkg_leaves_example_tileset_size, bkg_leaves_example_tileset);
    set_bkg_tiles(0, 0, 20, 18, bkg_leaves_example_tilemap);
}