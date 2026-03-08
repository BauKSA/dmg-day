#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_22_H
#define MAP_22_H

void Map_22_Init(Scene *scene, Entity scene_player);
void Map_22_Update(Scene *scene);

void Map_22_InitNPC(void);

extern Scene Map_22;

void Map_22_Create(void);

#endif // MAP_22_H