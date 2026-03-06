#pragma bank 2

#include "map_13.h"
#include "map_13_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/1-3/map_1-3.h"

void Map_13_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_13_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = MAP_12;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = MAP_23;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_1_3_tileset_size, map_1_3_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_1_3_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}