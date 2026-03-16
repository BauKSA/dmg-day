#pragma bank 1

#include "map_02.h"
#include "map_02_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/0-2/map_0-2.h"

void Map_02_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_02_collision;
    CurrentMapData.npc_count = 1;
    CurrentMapData.npc[0] = npc_1;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    CurrentMapData.spawner.right = MAP_03;
    CurrentMapData.spawner.left = MAP_01;
    CurrentMapData.spawner.up = NONE;
    CurrentMapData.spawner.down = MAP_12;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_0_2_tileset_size, map_0_2_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_0_2_tilemap);

    draw_actor(player);
    Map_02_InitNPC();

    actual_tile.prev = 0;
    actual_tile.value = 0;
}