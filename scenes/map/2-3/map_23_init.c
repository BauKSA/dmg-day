#pragma bank 3

#include "./map_23_collision.h"
#include "map_23.h"

#include "../map_data.h"

#include "../../../include/all_scenes.h"
#include "../../../include/draw.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"
#include "../../../include/input.h"

#include "../../../assets/sprites/backgrounds/maps/2-3/map_2-3.h"

static void map_23_event()
{
  if (back == 1)
  {
    keys = 0;
    prev_keys = 0;

    back = 0;

    return;
  }

  CurrentMapData.event_active = 1;
}

void Map_23_Init(Scene *scene, Entity scene_player)
{
  init_player();

  Map_23_InitNPC();
  Map_23_InitDialogues();

  CurrentMapData.player = player;
  CurrentMapData.npc_count = 1;
  CurrentMapData.npc[0] = npc_1;
  CurrentMapData.collision_map = map_23_collision;

  CurrentMapData.spawner.right = NONE;
  CurrentMapData.spawner.left = MAP_22;
  CurrentMapData.spawner.up = MAP_13;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 1;
  CurrentMapData.events[0] = map_23_event;
  CurrentMapData.event_active = 0;

  scene->data = &CurrentMapData;

  set_bkg_data(0, map_2_3_tileset_size, map_2_3_tileset);
  set_bkg_tiles(0, 0, 20, 18, map_2_3_tilemap);

  draw_actor(player);
  draw_actor(npc_1);

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
