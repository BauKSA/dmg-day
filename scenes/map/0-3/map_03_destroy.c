#pragma bank 1

#include <stdint.h>

#include "map_03.h"

#include "../../../include/scene.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

void Map_03_Destroy(Scene *scene)
{
    if (dialogue_phase[(uint8_t)NPC_ANTEOJOS] != 0)
        return;

    if (relation_stats[(uint8_t)NPC_ANTEOJOS] != 1)
        return;

    if (tmp_03_relation == 2)
        relation_stats[(uint8_t)NPC_ANTEOJOS] = 2;
    else
        relation_stats[(uint8_t)NPC_ANTEOJOS] = 0;
}