#pragma bank 1

#include <gb/gb.h>

#include "map_03.h"

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"

#include "../map_data.h"

void Map_03_CheckInput()
{
    if (CurrentMapData.event_active == 0)
        return;

    if (!(keys & J_A) && (prev_keys & J_A))
    {
        Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ANTEOJOS, 0, 0, NONE);
        tmp_03_relation = 2;
    }
}
