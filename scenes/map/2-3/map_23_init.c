#include "map_23.h"

#include "../map_data.c"

#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/scene.h"

#include "../../../assets/sprites/backgrounds/maps/2-3/map_2-3.h"

void Map_23_Init(Scene *scene, Entity scene_player) {
  init_player();

  CurrentMapData.player = player;
  CurrentMapData.npc_count = 0;
}
