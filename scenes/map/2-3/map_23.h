#ifndef MAP_23_H
#define MAP_23_H

#include "../../../include/entity.h"
#include "../../../include/scene.h"

void Map_23_Init(Scene *scene, Entity scene_player);
void Map_23_Update(Scene *scene);

void Map_23_InitNPC(void);
void Map_23_InitDialogues(void);
void Map_23_CheckInput(void);

extern Scene Map_23;

void Map_23_Create(void);

#endif // !MAP_23_H
