#ifndef _INVENTORYSCENE_
#define _INVENTORYSCENE_

#include <stdlib.h>

#include "../../include/entity.h"
#include "../../include/game.h"
#include "../../include/scene.h"

void InventoryScene_Init(Scene *scene, Entity scene_player);
void InventoryScene_Update(Scene *scene);

extern Scene InventoryScene;

void InventoryScene_Create(void);
void InventoryScene_CheckInput(void);
void InventoryScene_InitArrow(void);
void InventoryScene_DrawCoins(void);

#endif //_INVENTORYSCENE_
