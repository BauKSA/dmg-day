#pragma bank 1

#include "map_00.h"
#include "map_00_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/0-0/map_0-0.h"

void Map_00_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_00_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    CurrentMapData.spawner.right = NONE;
    CurrentMapData.spawner.left = NONE;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = MAP_10;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_0_0_tileset_size, map_0_0_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_0_0_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}