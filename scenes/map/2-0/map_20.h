#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_20_H
#define MAP_20_H

void Map_20_Init(Scene *scene, Entity scene_player);
void Map_20_Update(Scene *scene);

extern Scene Map_20;

void Map_20_Create(void);

#endif // MAP_20_H
