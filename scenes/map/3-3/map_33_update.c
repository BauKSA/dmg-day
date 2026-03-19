#pragma bank 5

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/npcs.h"
#include "../../../include/scene.h"
#include "../../map/auto_clean.h"
#include "../../map/map_data.h"
#include "../../map/map_player_movement.h"

#include "./map_33.h"

void Map_33_Update(Scene *scene) {
  Map_AutoClean();

  Map_33_CheckInput();
  Map_PlayerMovement();

  MapData *data = (MapData *)scene->data;

  update_animation(animation);
  update_animation(&animation[npc_1]);

  draw_actor(data->player);
  draw_actor(npc_1);

  Map_Collision(scene);

  return;
}
