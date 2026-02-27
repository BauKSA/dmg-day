#include <gb/gb.h>

#include "../../assets/chars/numbers.h"
#include "../../include/inventory.h"
#include "../../include/money.h"
#include "../../include/player.h"
#include "../../include/scene.h"
#include "inventory_scene.h"

#include "../../assets/sprites/backgrounds/inventory/inventory_bkg.h"
#include "../../assets/sprites/inventory/items/branch/spr_Branch.h"

void InventoryScene_DrawCoins() {
  uint8_t thousands = ((money / 1000) % 10) + NUMBER_TILESET_START;
  uint8_t hundreds = ((money / 100) % 10) + NUMBER_TILESET_START;
  uint8_t tens = ((money / 10) % 10) + NUMBER_TILESET_START;
  uint8_t units = (money % 10) + NUMBER_TILESET_START;

  set_bkg_tiles(INVENTORY_COIN_STARTS_X, INVENTORY_COIN_STARTS_Y, 1, 1,
                &thousands);
  set_bkg_tiles(INVENTORY_COIN_STARTS_X + 1, INVENTORY_COIN_STARTS_Y, 1, 1,
                &hundreds);
  set_bkg_tiles(INVENTORY_COIN_STARTS_X + 2, INVENTORY_COIN_STARTS_Y, 1, 1,
                &tens);
  set_bkg_tiles(INVENTORY_COIN_STARTS_X + 3, INVENTORY_COIN_STARTS_Y, 1, 1,
                &units);
}

void InventoryScene_Init(Scene *scene, Entity player) {
  scene->data = NULL;
  init_arrow();

  const uint8_t branch_tile = 53;

  unsigned char _previous_bank = _current_bank;
  SWITCH_ROM_MBC1(1);

  set_bkg_data(0, inventory_bkg_tileset_size, inventory_bkg_tileset);
  set_bkg_tiles(0, 0, 20, 18, inventory_bkg_tilemap);

  for (uint8_t i = 0; i < INVENTORY_ITEMS; i++) {
    if (inventory[i].active == 0)
      continue;

    set_bkg_data(INVENTORY_ITEMS_START, 1, spr_Branch);
    set_bkg_tiles(5, 7, 1, 1, &branch_tile);
  }

  InventoryScene_DrawCoins();

  SWITCH_ROM_MBC1(_previous_bank);
}
