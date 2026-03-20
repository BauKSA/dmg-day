#pragma bank 1

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/scene.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "map_03.h"

void Map_03_Update(Scene *scene)
{
    Map_AutoClean();

    Map_03_CheckInput();
    Map_PlayerMovement();

    MapData *data = (MapData *)scene->data;

    update_animation(animation);
    draw_actor(data->player);
    draw_actor(npc_1);

    Map_Collision(scene);
    Map_03_CheckItems();

    return;
}
