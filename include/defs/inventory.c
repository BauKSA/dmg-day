#include "../inventory.h"
#include "../entity.h"

//Sprites
#include "../../assets/sprites/inventory/spr_InventoryArrow_idle.h"

Entity arrow;

void init_arrow(void)
{
    arrow = create_entity();

    position.x[arrow] = 56;
    position.y[arrow] = 72;

    position.fixed_x[arrow] = position.x[arrow] << 8;
    position.fixed_y[arrow] = position.y[arrow] << 8;

    render.tile_start[arrow] = 0;
    render.tile_count[arrow] = 1;
    render.vertical[arrow] = TRUE;

    const unsigned char *arrow_idle[] = { spr_InventoryArrow_idle };

    init_animation(arrow, &animation[arrow], 0, arrow_idle, 1, DEFAULT_ANIMATION_SPEED, 1);
}