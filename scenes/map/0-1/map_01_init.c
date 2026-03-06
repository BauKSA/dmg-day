#pragma bank 1

#include "map_01.h"
#include "map_01_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/0-1/map_0-1.h"

void Map_01_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_01_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    CurrentMapData.spawner.right = MAP_02;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = MAP_11;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_0_1_tileset_size, map_0_1_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_0_1_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}