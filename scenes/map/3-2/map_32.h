#ifndef MAP_32_H
#define MAP_32_H

#include "../../../include/entity.h"
#include "../../../include/scene.h"

void Map_32_Init(Scene *scene, Entity scene_player);
void Map_32_Update(Scene *scene);

extern Scene Map_32;

void Map_32_Create(void);

#endif // !MAP_32_H
