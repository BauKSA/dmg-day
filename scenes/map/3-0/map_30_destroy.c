#pragma bank 4

#include "map_30.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void Map_30_Destroy(Scene *scene)
{
    dialogue_phase[(uint8_t)NPC_ESCOBA]++;
    if (dialogue_phase[(uint8_t)NPC_ESCOBA] > 3)
        dialogue_phase[(uint8_t)NPC_ESCOBA] = 3;

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 3)
        return;

    if (tmp_relation == 2)
        relation_stats[(uint8_t)NPC_ESCOBA] = 2;
    else
        relation_stats[(uint8_t)NPC_ESCOBA] = 0;
}