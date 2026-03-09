#pragma bank 3

#include <gb/gb.h>

#include "map_22.h"
#include "../../../include/input.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void Map_22_CheckInput()
{
    if (CurrentMapData.event_active == 0)
        return;

    if (!(keys & J_A) && (prev_keys & J_A))
    {
        uint8_t pepe = 0;
        Scene_DrawNPCLine(npc_1, (uint8_t)NPC_MARTIN, 0, 0, NONE);
        temp_relation = 2;
    }
}