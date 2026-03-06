#pragma bank 4

#include "./map_33.h"
#include "./map_33_collision.h"

#include "../map_data.h"

#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"

#include "../../../assets/sprites/backgrounds/maps/3-3/map_3-3.h"

void Map_33_Init(Scene *scene, Entity scene_player)
{
  init_player();

  CurrentMapData.player = player;
  CurrentMapData.npc_count = 0;
  CurrentMapData.collision_map = map_33_collision;

  CurrentMapData.spawner.right = NONE;
  CurrentMapData.spawner.left = MAP_32;
  CurrentMapData.spawner.up = NONE;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 0;
  CurrentMapData.event_active = 0;

  scene->data = &CurrentMapData;

  set_bkg_data(0, map_3_3_tileset_size, map_3_3_tileset);
  set_bkg_tiles(0, 0, 20, 18, map_3_3_tilemap);

  draw_actor(player);

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
