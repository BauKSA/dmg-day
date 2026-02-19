#include <gb/gb.h>

#include "../../../include/scene.h"
#include "../../../include/scene_manager.h"
#include "../../../include/all_scenes.h"
#include "../../../include/action.h"
#include "../../../include/draw.h"
#include "../../../include/animation.h"
#include "../../../include/input.h"
#include "../../map/map_data.h"
#include "../../map/map_player_movement.h"

#include "map_00.h"

void Map_00_Update(Scene *scene)
{
    Map_PlayerMovement();

    MapData *data = (MapData *)scene->data;

    for (size_t i = 0; i < data->npc_count; i++)
    {
        draw_actor(data->npc[i]);
    }

    update_animation(animation);
    draw_actor(data->player);

    Map_Collision(scene);

    if (!(keys & J_A) && (prev_keys & J_A))
    {
        scene_manager->change_scene(MG_LEAVES, player);
    }

    return;
}