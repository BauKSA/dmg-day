#pragma bank 5

#include "../../include/player.h"
#include "../../include/position.h"
#include "../../include/scene.h"
#include "../../include/animation.h"
#include "../../include/render.h"
#include "../../include/draw.h"
#include "../../include/npcs.h"
#include "../../include/language.h"
#include "../../include/char_to_tile.h"
#include "../../include/text_positions.h"

#include "./inventory_scene.h"

#include "../../assets/sprites/backgrounds/inventory/inventory_bkg.h"
#include "../../assets/chars/chars.h"

#include <gb/gb.h>

void InventoryScene_Init(Scene *scene, Entity scene_player)
{
  scene->data = NULL;

  set_bkg_data(0, inventory_bkg_tileset_size, inventory_bkg_tileset);
  set_bkg_tiles(0, 0, 20, 18, inventory_bkg_tilemap);
}