#pragma bank 7

#include "map_20.h"
#include "map_20_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/2-0/map_2-0.h"

static void Map_20_event()
{
    if (npc_20_active == 0)
        return;

    if (CurrentMapData.event_active == 1)
        return;

    CurrentMapData.event_active = 1;

    dialogue_phase[(uint8_t)NPC_LIBRO] = 1;

    Map_20_InitDialogues();

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_LIBRO, 0, 0, NONE);
}

void Map_20_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_20_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 1;
    CurrentMapData.event_active = 0;
    CurrentMapData.events[0] = Map_20_event;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = MAP_10;
    CurrentMapData.spawner.down = MAP_30;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_2_0_tileset_size, map_2_0_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_2_0_tilemap);

    if (npc_20_active == 1)
    {
        Map_20_InitDialogues();
        Map_20_InitNPC();

        uint8_t empty_tile = 255;
        set_bkg_tile_xy(7, 5, empty_tile);
        set_bkg_tile_xy(8, 5, empty_tile);
        set_bkg_tile_xy(7, 6, empty_tile);
        set_bkg_tile_xy(8, 6, empty_tile);
    }

    draw_actor(player);
    draw_actor(npc_1);

    actual_tile.prev = 0;
    actual_tile.value = 0;

    if (npc_20_active == 1 && dialogue_phase[(uint8_t)NPC_LIBRO] == 0)
        Scene_DrawNPCLine(npc_1, (uint8_t)NPC_LIBRO, 0, 0, NONE);
}