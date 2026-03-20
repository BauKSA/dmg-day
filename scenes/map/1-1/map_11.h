#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/market.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_11_H
#define MAP_11_H

void Map_11_Init(Scene *scene, Entity scene_player);
void Map_11_Update(Scene *scene);

extern Scene Map_11;
extern MarketItem stock_items[10];
extern uint8_t stock_items_count;

void Map_11_Create(void);
void Map_11_CheckInput(void);
void Map_11_InitOptionActor(void);

#endif // MAP_11_H
