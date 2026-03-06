#pragma bank 2

#include "map_22.h"
#include "map_22_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/2-2/map_2-2.h"

void Map_22_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_22_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.spawner.right = MAP_23;
    CurrentMapData.spawner.left = MAP_21;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = MAP_32;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_2_2_tileset_size, map_2_2_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_2_2_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}