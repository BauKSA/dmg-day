#pragma bank 4

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/npcs.h"
#include "../../../include/scene.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "./map_31.h"

void Map_31_Update(Scene *scene)
{
  Map_AutoClean();

  Map_31_CheckInput();
  Map_PlayerMovement();

  MapData *data = (MapData *)scene->data;

  update_animation(animation);
  update_animation(&animation[npc_1]);

  draw_actor(data->player);
  draw_actor(npc_1);
  draw_actor(npc_2);

  Map_Collision(scene);

  return;
}