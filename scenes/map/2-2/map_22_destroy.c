#pragma bank 3

#include "map_22.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

// debug
#include "../../../include/inventory.h"

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

    for (uint8_t i = 0; i < INVENTORY_ITEMS; i++)
    {
        if (inventory[i].item == GLASSES)
        {
            inventory[i].active = 1;
            return;
        }
    }
}