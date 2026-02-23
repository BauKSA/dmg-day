#include <gb/gb.h>
#include "./mg_leaves.h"
#include "../../../assets/sprites/backgrounds/minigames/leaves/bkg_leaves_example.h"

void Mg_Leaves_LoadBKG()
{
    unsigned char _previous_bank = _current_bank;
    SWITCH_ROM_MBC1(1);

    set_bkg_data(0, bkg_leaves_example_tileset_size, bkg_leaves_example_tileset);
    set_bkg_tiles(0, 0, 20, 18, bkg_leaves_example_tilemap);

    SWITCH_ROM_MBC1(_previous_bank);
}