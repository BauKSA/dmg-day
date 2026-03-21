#pragma bank 2

#include <gb/gb.h>

#include "map_13.h"

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/music.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/inventory.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"
#include "../../../include/scene_manager.h"
#include "../../../include/all_scenes.h"

#include "../map_data.h"
#include "../../inventory/inventory_scene.h"

void Map_13_CheckInput()
{
    if (CurrentMapData.event_active == 0)
        return;

    if (!(keys & J_A) && (prev_keys & J_A))
    {
        uint8_t npc = npc_1;
        uint8_t npc_map = (uint8_t)NPC_BOCA;
        uint8_t npc_i = 0;

        if (CurrentMapData.event_active == 2)
        {
            npc = npc_2;
            npc_map = (uint8_t)NPC_GALLINA;
            npc_i = 1;
        }

        Scene_DrawNPCLine(npc, npc_map, npc_i, 0, NONE);

        if (CurrentMapData.event_active == 2 && glasses_delivered == 0 && relation_stats[(uint8_t)NPC_GALLINA] == 2)
        {

            for (uint8_t i = 0; i < 240; i++)
                vsync();

            cache_player_position();

            position.y[player] = 0;
            position.y[npc_1] = 0;
            position.y[npc_2] = 0;

            draw_actor(player);
            draw_actor(npc_1);
            draw_actor(npc_2);

            next_scene = INVENTORY;

            NewItemScreen(GLASSES);
        }
    }
}
