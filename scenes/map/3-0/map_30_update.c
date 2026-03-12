#pragma bank 4

#include "../../../include/animation.h"
#include "../../../include/npcs.h"
#include "../../../include/draw.h"
#include "../../../include/scene.h"
#include "../../../include/npc_stats_map.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "./map_30.h"

void Map_30_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();
  Map_30_CheckInput();

  MapData *data = (MapData *)scene->data;

  update_animation(animation);
  update_animation(&animation[npc_1]);

  draw_actor(data->player);
  draw_actor(npc_1);

  Map_Collision(scene);

  if (mg_ended == 1)
  {
    mg_ended = 0;

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, 0, NONE);
  }

  return;
}