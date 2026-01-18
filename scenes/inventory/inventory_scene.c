#include "inventory_scene.h"
#include "../../include/scene.h"

Scene InventoryScene;

void InventoryScene_Create(void)
{
    InventoryScene.init = InventoryScene_Init;
    InventoryScene.update = InventoryScene_Update;

    InventoryScene.data = NULL;
}