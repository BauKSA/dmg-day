#pragma bank 1

#include "map_03.h"
#include "map_03_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"
#include "../../../include/npcs.h"

#include "../../../assets/sprites/backgrounds/maps/0-3/map_0-3.h"

void Map_03_event()
{
    CurrentMapData.event_active = 1;
}

void Map_03_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_03_collision;
    CurrentMapData.npc_count = 1;
    CurrentMapData.npc[0] = npc_1;

    CurrentMapData.event_count = 1;
    CurrentMapData.event_active = 0;
    CurrentMapData.events[0] = Map_03_event;

    CurrentMapData.receive_items = 1;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = MAP_02;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = NONE;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_0_3_tileset_size, map_0_3_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_0_3_tilemap);

    draw_actor(player);
    draw_actor(npc_1);

    Map_03_InitDialogues();
    Map_03_InitNPC();

    actual_tile.prev = 0;
    actual_tile.value = 0;
}