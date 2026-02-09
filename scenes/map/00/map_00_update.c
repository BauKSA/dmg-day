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
    update_animation(animation);

    MapData *data = (MapData *)scene->data;
    draw_actor(data->player);
    return;
}