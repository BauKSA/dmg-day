#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_11_H
#define MAP_11_H

void Map_11_Init(Scene *scene, Entity scene_player);
void Map_11_Update(Scene *scene);

extern Scene Map_11;

void Map_11_Create(void);

#endif // MAP_11_H
