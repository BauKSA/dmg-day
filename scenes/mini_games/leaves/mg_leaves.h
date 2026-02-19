#include <stdlib.h>

#include "../../../include/game.h"
#include "../../../include/entity.h"
#include "../../../include/npc_lines.h"

#ifndef MG_LEAVES_H
#define MG_LEAVES_H

void Mg_Leaves_Init(Scene *scene, Entity scene_player);
void Mg_Leaves_Update(Scene *scene);
void Mg_Leaves_Player_Init();

extern Scene Mg_Leaves;

void Mg_Leaves_Create(void);

#endif // MG_LEAVES_H