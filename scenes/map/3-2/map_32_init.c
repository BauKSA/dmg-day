#include "./map_32.h"
#include "./map_32_collision.h"

#include "../map_data.h"

#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"

#include "../../../assets/sprites/backgrounds/maps/3-2/map_3-2.h"

void Map_32_Init(Scene *scene, Entity scene_player)
{
  init_player();

  CurrentMapData.player = player;
  CurrentMapData.npc_count = 0;
  CurrentMapData.collision_map = map_32_collision;

  CurrentMapData.spawner.right = NONE;
  CurrentMapData.spawner.left = NONE;
  CurrentMapData.spawner.up = MAP_22;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 0;
  CurrentMapData.event_active = 0;

  scene->data = &CurrentMapData;

  set_bkg_data(0, map_3_2_tileset_size, map_3_2_tileset);
  set_bkg_tiles(0, 0, 20, 18, map_3_2_tilemap);

  draw_actor(player);

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
