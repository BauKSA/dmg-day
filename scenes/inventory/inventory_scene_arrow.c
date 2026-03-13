#pragma bank 5

#include "inventory_scene.h"
#include "../../include/player.h"
#include "../../include/position.h"
#include "../../include/animation.h"
#include "../../include/render.h"
#include "../../include/draw.h"
#include "../../include/npcs.h"

#include "../../assets/sprites/backgrounds/language_select/spr_language_arrow.h"

void InventoryScene_InitArrow()
{
    position.x[option_actor] = 48;
    position.y[option_actor] = 74;

    position.fixed_x[option_actor] = position.x[option_actor];
    position.fixed_y[option_actor] = position.y[option_actor];

    render.tile_start[option_actor] = 0;
    render.tile_count[option_actor] = 1;
    render.vertical[option_actor] = TRUE;

    const unsigned char *arrow_idle[] = {spr_language_arrow0};

    init_animation(option_actor, &animation[option_actor], 0, arrow_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(option_actor);
}