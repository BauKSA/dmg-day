#pragma bank 1

#include "map_00.h"
#include "map_00_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/scene_manager.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/0-0/map_0-0.h"

void Map_00_event()
{
    CurrentMapData.event_active = 1;
}

void Map_00_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_00_collision;
    CurrentMapData.npc_count = 1;
    CurrentMapData.npc[0] = npc_1;

    CurrentMapData.event_count = 1;
    CurrentMapData.event_active = 0;
    CurrentMapData.events[0] = Map_00_event;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = MAP_10;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_0_0_tileset_size, map_0_0_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_0_0_tilemap);

    Map_00_InitNPC();
    Map_00_InitDialogues();

    draw_actor(player);
    draw_actor(npc_1);

    actual_tile.prev = 0;
    actual_tile.value = 0;

    if (dialogue_phase[(uint8_t)NPC_TIENDA] == 1)
    {
        Scene_DrawNPCLine(npc_1, (uint8_t)NPC_TIENDA, 0, 0, NONE);

        for (uint8_t i = 0; i < 120; i++)
            vsync();

        if (relation_stats[(uint8_t)NPC_TIENDA] == 0)
            next_scene = GAME_OVER;
        else
            next_scene = YOU_WIN;
    }
}