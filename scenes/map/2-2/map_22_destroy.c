#pragma bank 3

#include "map_22.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void Map_22_Destroy(Scene *scene)
{
    dialogue_phase[(uint8_t)NPC_MARTIN]++;
    if (dialogue_phase[(uint8_t)NPC_MARTIN] > 3)
        dialogue_phase[(uint8_t)NPC_MARTIN] = 3;

    if (temp_relation == 2)
        relation_stats[(uint8_t)NPC_MARTIN] = 2;
    else
        relation_stats[(uint8_t)NPC_MARTIN] = 0;

    npc_appeared = 1;
}