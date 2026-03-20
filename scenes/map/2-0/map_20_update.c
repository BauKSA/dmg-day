#pragma bank 7

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/npcs.h"
#include "../../../include/scene.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "map_20.h"

void Map_20_Update(Scene *scene)
{
  if (CurrentMapData.event_active == 0)
    Map_AutoClean();

  Map_20_CheckInput();
  Map_PlayerMovement();

  MapData *data = (MapData *)scene->data;

  update_animation(animation);

  draw_actor(data->player);
  draw_actor(npc_1);

  Map_Collision(scene);

  return;
}
