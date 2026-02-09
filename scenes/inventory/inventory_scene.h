#ifndef INVENTORY_SCENE_H
#define INVENTORY_SCENE_H

#include <stdlib.h>

#include "../../include/game.h"
#include "../../include/entity.h"

extern Scene InventoryScene;

void InventoryScene_Init(Scene* scene, Entity player);
void InventoryScene_Update(Scene* scene);

void InventoryScene_Create(void);

#endif //INVENTORY_SCENE_H