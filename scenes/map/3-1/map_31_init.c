#pragma bank 4

#include "./map_31.h"
#include "./map_31_collision.h"

#include "../map_data.h"

#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"

#include "../../../assets/sprites/backgrounds/maps/3-1/map_3-1.h"

void Map_31_Init(Scene *scene, Entity scene_player)
{
  init_player();
  Map_31_InitNPCs();

  CurrentMapData.player = player;
  CurrentMapData.npc_count = 0;
  CurrentMapData.collision_map = map_31_collision;

  CurrentMapData.spawner.right = MAP_32;
  CurrentMapData.spawner.left = MAP_30;
  CurrentMapData.spawner.up = NONE;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 0;
  CurrentMapData.event_active = 0;

  scene->data = &CurrentMapData;

  set_bkg_data(0, map_3_1_tileset_size, map_3_1_tileset);
  set_bkg_tiles(0, 0, 20, 18, map_3_1_tilemap);

  draw_actor(player);

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
