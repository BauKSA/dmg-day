#include <stdlib.h>

#include "../../../include/game.h"
#include "../../../include/entity.h"

#ifndef MAP_00_H
#define MAP_00_H

void Map_00_Init(Scene *scene, Entity *player);
void Map_00_Update(Scene *scene);

extern Scene Map_00;

void Map_00_Create(void);

#endif // MAP_00_H