#pragma bank 4

#include "./map_32.h"
#include "./map_32_collision.h"

#include "../map_data.h"

#include "../../../include/draw.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"
#include "../../../include/all_scenes.h"

#include "../../../assets/sprites/backgrounds/maps/3-2/map_3-2.h"

static void map_32_event()
{
  CurrentMapData.event_active = 1;
}

void Map_32_Init(Scene *scene, Entity scene_player)
{
  init_player();

  CurrentMapData.player = player;
  CurrentMapData.collision_map = map_32_collision;

  CurrentMapData.spawner.right = MAP_33;
  CurrentMapData.spawner.left = MAP_31;
  CurrentMapData.spawner.up = MAP_22;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 1;
  CurrentMapData.event_active = 0;
  CurrentMapData.events[0] = map_32_event;

  scene->data = &CurrentMapData;

  set_bkg_data(0, map_3_2_tileset_size, map_3_2_tileset);
  set_bkg_tiles(0, 0, 20, 18, map_3_2_tilemap);

  draw_actor(player);

  // NPC
  if (map_32_npc_active == 1)
  {
    uint8_t empty_tile = 255;
    set_bkg_tile_xy(7, 10, empty_tile);
    set_bkg_tile_xy(8, 10, empty_tile);
    set_bkg_tile_xy(7, 11, empty_tile);
    set_bkg_tile_xy(8, 11, empty_tile);

    CurrentMapData.npc_count = 1;
    CurrentMapData.npc[0] = npc_1;

    Map_32_InitNPC();
    Map_32_InitDialogues();

    draw_actor(npc_1);
  }else{
        CurrentMapData.npc_count = 0;
  }

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
