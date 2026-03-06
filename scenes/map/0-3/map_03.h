#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_03_H
#define MAP_03_H

void Map_03_Init(Scene *scene, Entity scene_player);
void Map_03_Update(Scene *scene);

extern Scene Map_03;

void Map_03_Create(void);

#endif // MAP_03_H
