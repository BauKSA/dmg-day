#pragma bank 4

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/scene.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/mgm_states.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "./map_32.h"

void Map_32_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();
  Map_32_CheckInput();

  MapData *data = (MapData *)scene->data;

  update_animation(animation);

  draw_actor(data->player);
  draw_actor(npc_1);

  Map_Collision(scene);

  if (mg_32_tmp != MGM_states.mg_homework)
  {
    mg_32_tmp = MGM_states.mg_homework;

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_TAREA, 0, 0, NONE);
  }

  return;
}
