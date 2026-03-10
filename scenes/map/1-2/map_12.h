#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_12_H
#define MAP_12_H

void Map_12_Init(Scene *scene, Entity scene_player);
void Map_12_Update(Scene *scene);

void Map_12_InitNPC(void);
void Map_12_InitDialogues(void);
void Map_12_CheckInput(void);

extern Scene Map_12;

void Map_12_Create(void);

#endif // MAP_12_H
