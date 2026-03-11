#pragma bank 2

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/scene.h"
#include "../../map/auto_clean.h"
#include "../../map/map_data.h"
#include "../../map/map_player_movement.h"

#include "map_12.h"

void Map_12_Update(Scene *scene) {
  Map_AutoClean();

  Map_PlayerMovement();

  MapData *data = (MapData *)scene->data;

  update_animation(animation);
  draw_actor(data->player);
  draw_actor(npc_1);

  Map_Collision(scene);
  Map_12_CheckInput();
  Map_12_CheckItems();

  return;
}
