#pragma bank 5

#include "./map_33.h"
#include "./map_33_collision.h"

#include "../map_data.h"

#include "../../../include/all_scenes.h"
#include "../../../include/draw.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"

static void Map_33_event() { CurrentMapData.event_active = 1; }

void Map_33_Init(Scene *scene, Entity scene_player) {
  init_player();

  CurrentMapData.player = player;
  CurrentMapData.npc_count = 1;
  CurrentMapData.npc[0] = npc_1;
  CurrentMapData.collision_map = map_33_collision;

  CurrentMapData.spawner.right = NONE;
  CurrentMapData.spawner.left = MAP_32;
  CurrentMapData.spawner.up = NONE;
  CurrentMapData.spawner.down = NONE;

  CurrentMapData.event_count = 1;
  CurrentMapData.event_active = 0;
  CurrentMapData.events[0] = Map_33_event;

  scene->data = &CurrentMapData;

  Map_33_LoadBKG();
  Map_33_InitNPC();
  Map_33_InitDialogues();

  draw_actor(player);
  draw_actor(npc_1);

  actual_tile.prev = 0;
  actual_tile.value = 0;
}
