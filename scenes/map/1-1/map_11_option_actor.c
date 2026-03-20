#pragma bank 2

#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/animation.h"
#include "../../../include/render.h"

#include "../../../assets/sprites/backgrounds/maps/2-3/map_2-3.h"

void Map_11_InitOptionActor()
{
    position.x[option_actor] = 24;
    position.y[option_actor] = 56;

    position.fixed_x[option_actor] = position.x[option_actor];
    position.fixed_y[option_actor] = position.y[option_actor];

    render.tile_start[option_actor] = 0;
    render.tile_count[option_actor] = 1;
    render.vertical[option_actor] = TRUE;

    const unsigned char *arrow_idle[] = {spr_RightArrow};

    init_animation(option_actor, &animation[option_actor], 0, arrow_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 1);
}