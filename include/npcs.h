#ifndef _NPCS_
#define _NPCS_
#include "./entity.h"
#include "./all_scenes.h"

#define MAX_NPCS 15

extern Entity npc_1;
extern Entity npc_2;
extern Entity option_actor;

void init_NPCs();
void Scene_DrawNPCLine(
    Entity npc,
    uint8_t npc_map,
    uint8_t npc_index,
    uint8_t has_minigame,
    enum AllScenes minigame);

extern uint8_t humor_stats[MAX_NPCS];

#endif //_NPCS_