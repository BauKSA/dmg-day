#include <gb/gb.h>
#include "./mg_leaves.h"
#include "../../../assets/sprites/backgrounds/template/template.h"

void Mg_Leaves_LoadBKG()
{
    unsigned char _previous_bank = _current_bank;
    SWITCH_ROM_MBC1(1);

    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);

    SWITCH_ROM_MBC1(_previous_bank);
}