#pragma bank 7

#include <gb/gb.h>

#include "../../include/scene.h"

#include "you_win.h"

#include "../../assets/sprites/backgrounds/you_win/bkg_you_win.h"

void YouWin_Init(Scene *scene, Entity player)
{
    set_bkg_data(0, bkg_you_win_tileset_size, bkg_you_win_tileset);
    set_bkg_tiles(0, 0, 20, 18, bkg_you_win_tilemap);
}