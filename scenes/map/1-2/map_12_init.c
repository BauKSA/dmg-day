#pragma bank 2

#include "map_12.h"
#include "map_12_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/1-2/map_1-2.h"

void Map_12_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_12_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    CurrentMapData.spawner.right = MAP_13;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = MAP_02;
    CurrentMapData.spawner.down = NONE;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_1_2_tileset_size, map_1_2_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_1_2_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}