#ifndef _MAP_33_
#define _MAP_33_

#include "../../../include/entity.h"
#include "../../../include/scene.h"

void Map_33_Init(Scene *scene, Entity scene_player);
void Map_33_Update(Scene *scene);

extern Scene Map_33;

void Map_33_Create(void);
void Map_33_InitNPC(void);
void Map_33_LoadBKG(void);
void Map_33_InitDialogues(void);
void Map_33_CheckInput(void);

#endif // _MAP_33_
