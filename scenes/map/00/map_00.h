#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"
#include "../../../scenes/map/map_data.h"

#ifndef MAP_00_H
#define MAP_00_H

extern const DialoguePerRelation dialogue_00;

void Map_00_Init(Scene *scene, Entity scene_player);
void Map_00_Update(Scene *scene);
void Map_00_NPC_Init(Scene *scene);
void Map_00_InitDialogues(void);
void Map_00_CheckItems(void);

extern Scene Map_00;

void Map_00_Create(void);

#endif // MAP_00_H
