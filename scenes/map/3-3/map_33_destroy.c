#include "map_33.h"

#include "../../../include/scene.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void Map_33_Destroy(Scene *scene)
{
    if (update_33_dialogue == 1)
    {
        update_33_dialogue = 0;
        dialogue_phase[(uint8_t)NPC_SUPER] = 2;
    }
}