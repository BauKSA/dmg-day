#pragma bank 5

#include "inventory_scene.h"

void InventoryScene_Create()
{
    InventoryScene.init = InventoryScene_Init;
    InventoryScene.update = InventoryScene_Update;
    InventoryScene.bank = 5;

    InventoryScene.data = NULL;
}