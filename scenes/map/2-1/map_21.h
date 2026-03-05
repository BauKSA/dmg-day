#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_21_H
#define MAP_21_H

void Map_21_Init(Scene *scene, Entity scene_player);
void Map_21_Update(Scene *scene);

extern Scene Map_21;

void Map_21_Create(void);

#endif // MAP_21_H
