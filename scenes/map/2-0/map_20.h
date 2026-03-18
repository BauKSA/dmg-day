#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_20_H
#define MAP_20_H

typedef enum MissionBooks
{
    NONE_BOOK,
    WAR,
    HOBBIT,
    PRIDE,
    FIERRO
} MissionBooks;

void Map_20_Init(Scene *scene, Entity scene_player);
void Map_20_Update(Scene *scene);
void Map_20_Destroy(Scene *scene);

extern Scene Map_20;
extern uint8_t tmp_20_relation;
extern uint8_t npc_20_active;
extern uint8_t mission_20_active;
extern MissionBooks purchased_book;

void Map_20_Create(void);
void Map_20_InitNPC(void);
void Map_20_InitDialogues(void);
void Map_20_CheckInput(void);

#endif // MAP_20_H
