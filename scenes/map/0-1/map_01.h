#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_01_H
#define MAP_01_H

void Map_01_Init(Scene *scene, Entity scene_player);
void Map_01_Update(Scene *scene);

extern Scene Map_01;

void Map_01_Create(void);

#endif // MAP_01_H
