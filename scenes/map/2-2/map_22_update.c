#pragma bank 3

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/scene.h"
#include "../../../include/player.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "map_22.h"

void Map_22_Update(Scene *scene)
{
  Map_AutoClean();

  Map_PlayerMovement();

  MapData *data = (MapData *)scene->data;

  update_animation(&animation[player]);
  update_animation(&animation[npc_1]);

  draw_actor(npc_1);
  draw_actor(data->player);

  Map_Collision(scene);

  return;
}
