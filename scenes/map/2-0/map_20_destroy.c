#pragma bank 7
#include "map_20.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void Map_20_Destroy(Scene *scene)
{
    if (dialogue_phase[(uint8_t)NPC_LIBRO] != 0)
        return;
        
    dialogue_phase[(uint8_t)NPC_LIBRO]++;
    if (dialogue_phase[(uint8_t)NPC_LIBRO] > 3)
        dialogue_phase[(uint8_t)NPC_LIBRO] = 3;

    if (dialogue_phase[(uint8_t)NPC_LIBRO] == 3)
        return;

    if (tmp_20_relation == 2)
        relation_stats[(uint8_t)NPC_LIBRO] = 2;
    else
        relation_stats[(uint8_t)NPC_LIBRO] = 0;
}