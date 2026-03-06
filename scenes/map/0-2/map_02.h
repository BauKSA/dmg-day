#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_02_H
#define MAP_02_H

void Map_02_Init(Scene *scene, Entity scene_player);
void Map_02_Update(Scene *scene);

extern Scene Map_02;

void Map_02_Create(void);

#endif // MAP_02_H
