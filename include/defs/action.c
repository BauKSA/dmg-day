#include "../action.h"

#include "../player.h"
#include "../scene_manager.h"
#include "../can_move.h"
#include "../input.h"
#include "../speed.h"

Direction current_direction = DIR_NONE;

void move_up(Entity e)
{
    if (can_move.up == false)
        return;

    position.fixed_y[e] -= speed[e];
    position.y[e] = position.fixed_y[e] >> 8;
}

void move_down(Entity e)
{
    if (can_move.down == false)
        return;

    position.fixed_y[e] += speed[e];
    position.y[e] = position.fixed_y[e] >> 8;
}

void move_left(Entity e)
{
    if (can_move.left == false)
        return;

    position.fixed_x[e] -= speed[e];
    position.x[e] = position.fixed_x[e] >> 8;
}

void move_right(Entity e)
{
    if (can_move.right == false)
        return;

    position.fixed_x[e] += speed[e];
    position.x[e] = position.fixed_x[e] >> 8;
}