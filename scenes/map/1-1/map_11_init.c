#pragma bank 2

#include "map_11.h"
#include "map_11_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/1-1/map_1-1.h"

void Map_11_event()
{
    CurrentMapData.event_active = 1;
}

void Map_11_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_11_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 1;
    CurrentMapData.event_active = 0;
    CurrentMapData.events[0] = Map_11_event;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = MAP_01;
    CurrentMapData.spawner.down = NONE;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_1_1_tileset_size, map_1_1_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_1_1_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}