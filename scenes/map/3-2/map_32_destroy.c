#pragma bank 4

#include "map_32.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void Map_32_Destroy(Scene *scene)
{
    if (dialogue_phase[(uint8_t)NPC_TAREA] != 0)
        return;

    if (tmp_relation32 == 2)
        relation_stats[(uint8_t)NPC_TAREA] = 2;
    else
        relation_stats[(uint8_t)NPC_TAREA] = 0;
}