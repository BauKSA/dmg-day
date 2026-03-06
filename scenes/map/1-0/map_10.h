#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_10_H
#define MAP_10_H

void Map_10_Init(Scene *scene, Entity scene_player);
void Map_10_Update(Scene *scene);

extern Scene Map_10;

void Map_10_Create(void);

#endif // MAP_10_H
