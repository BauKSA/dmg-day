#include "map_21.h"
#include "map_21_collision.h"

#include "../map_data.h"

#include "../../../include/scene.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"

#include "../../../assets/sprites/backgrounds/maps/map_2-1.h"

void Map_21_Init(Scene *scene, Entity scene_player)
{
    init_player();

    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_21_collision;
    CurrentMapData.npc_count = 0;

    CurrentMapData.event_count = 0;
    CurrentMapData.event_active = 0;

    scene->data = &CurrentMapData;

    set_bkg_data(0, map_2_1_tileset_size, map_2_1_tileset);
    set_bkg_tiles(0, 0, 20, 18, map_2_1_tilemap);

    draw_actor(player);

    actual_tile.prev = 0;
    actual_tile.value = 0;
}