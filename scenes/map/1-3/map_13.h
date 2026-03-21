#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_13_H
#define MAP_13_H

void Map_13_Init(Scene *scene, Entity scene_player);
void Map_13_Update(Scene *scene);

extern Scene Map_13;
extern uint8_t glasses_delivered;

void Map_13_Create(void);
void Map_13_InitDialogues(void);
void Map_13_InitNPCs(void);
void Map_13_CheckInput(void);

#endif // MAP_13_H
