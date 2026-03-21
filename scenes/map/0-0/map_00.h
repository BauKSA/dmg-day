#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_00_H
#define MAP_00_H

void Map_00_Init(Scene *scene, Entity scene_player);
void Map_00_Update(Scene *scene);

extern Scene Map_00;
extern uint8_t game_boy_reserved;
extern uint8_t game_boy_purchased;

void Map_00_Create(void);
void Map_00_InitNPC(void);
void Map_00_InitDialogues(void);
void Map_00_CheckInput(void);

#endif // MAP_10_H
