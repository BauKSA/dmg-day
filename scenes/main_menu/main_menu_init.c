#include<gb/gb.h>
#include "./main_menu.h"
#include "../../include/player.h"
#include "../../include/scene.h"
#include "../../include/position.h"
#include "../../assets/sprites/backgrounds/main_menu/bkg_MainMenu.h"

void MainMenu_Init(Scene *scene, Entity scene_player)
{
    scene->data = NULL;

    unsigned char _previous_bank = _current_bank;
    SWITCH_ROM_MBC1(1);

    set_bkg_data(0, bkg_main_menu_tileset_size, bkg_main_menu_tileset);
    set_bkg_tiles(0, 0, 20, 18, bkg_main_menu_tilemap);

    SWITCH_ROM_MBC1(_previous_bank);
}