#pragma bank 1

#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/scene.h"
#include "../../map/map_data.h"
#include "../../map/auto_clean.h"
#include "../../map/map_player_movement.h"

#include "map_00.h"

void Map_00_Update(Scene *scene)
{
    Map_AutoClean();

    Map_PlayerMovement();

    MapData *data = (MapData *)scene->data;

    update_animation(animation);
    draw_actor(data->player);

    Map_00_CheckInput();
    Map_Collision(scene);

    return;
}
