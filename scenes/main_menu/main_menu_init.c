#include "../../assets/sprites/backgrounds/main_menu/bkg_MainMenu.h"
#include "../../include/player.h"
#include "../../include/position.h"
#include "../../include/scene.h"
#include "./main_menu.h"
#include <gb/gb.h>

// #include "../../include/huge/include/hUGEDriver.h"

void MainMenu_Init(Scene *scene, Entity scene_player) {
  scene->data = NULL;

  set_bkg_data(0, bkg_main_menu_tileset_size, bkg_main_menu_tileset);
  set_bkg_tiles(0, 0, 20, 18, bkg_main_menu_tilemap);

  //  hUGE_init(&test_song);
}
