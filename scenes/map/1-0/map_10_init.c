#pragma bank 2

#include "map_10.h"
#include "map_10_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/1-0/map_1-0.h"

void Map_10_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_10_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = MAP_00;
    CurrentMapData.spawner.down = MAP_20;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_1_0_tileset_size, map_1_0_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_1_0_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}