#include <gb/gb.h>

#include "../../../include/scene.h"
#include "../../../include/action.h"
#include "../../../include/draw.h"
#include "../../../include/animation.h"
#include "../../map/map_data.h"

#include "map_00.h"

void Map_00_Update(Scene *scene)
{
    check_input();
    
    MapData *data = (MapData *)scene->data;
    
    for(size_t i = 0; i < data->npc_count; i++){
        draw_actor(data->npc[i]);
    }
    
    update_animation(animation);
    draw_actor(data->player);

    Map_Collision(scene);

    return;
}