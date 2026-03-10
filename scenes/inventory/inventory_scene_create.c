#pragma bank 5

#include "inventory_scene.h"
#include "../../include/scene.h"

void InventoryScene_Create(void) {
  InventoryScene.init = InventoryScene_Init;
  InventoryScene.update = InventoryScene_Update;
  InventoryScene.bank = 5;
}
