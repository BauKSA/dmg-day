#include <gb/gb.h>

#include "./mg_leaves.h"
#include "../mg_player_movement.h"
#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/extra_actor.h"
#include "../../../include/random.h"
#include "../../../include/collision.h"
#include "../../../include/input.h"

void check_leaf_status()
{
    for (uint8_t i = 0; i <= extra_actor_index; i++)
    {
        if (leaf_active[i] == 0 && leaf_state[i] == FALLING)
        {
            if ((my_rand() % 400) == 0)
            {
                leaf_active[i] = 1;
                leaf_timer[i] = 0;
                leaf_y[i] = 24;

                continue;
            }

            continue;
        }

        if (leaf_state[i] == FALLING)
            leaf_y[i]++;

        if (leaf_y[i] >= 112 && leaf_state[i] == FALLING)
            leaf_state[i] = ON_FLOOR;

        if (leaf_state[i] == BEING_SWEPT_RIGHT && SWEEPING_FLAG)
            leaf_x[i] = position.x[mg_player] - 8;

        if (leaf_state[i] == BEING_SWEPT_LEFT && SWEEPING_FLAG)
            leaf_x[i] = position.x[mg_player] + 8;

        draw_extra(leaf_ids[i], leaf_x[i], leaf_y[i], 1, 1);
    }
}

void check_leaf_collision()
{
    uint8_t x1 = position.x[mg_player];

    for (uint8_t i = 0; i < LEAF_COUNT; i++)
    {
        if (leaf_state[i] == FALLING)
            continue;

        uint8_t x2 = leaf_x[i];

        if (x1 < x2 + 8 && x1 + 4 > x2)
        {
            if (x1 > x2)
                leaf_state[i] = BEING_SWEPT_RIGHT;

            if (x2 > x1)
                leaf_state[i] = BEING_SWEPT_LEFT;
        }
        else
        {
            leaf_state[i] = ON_FLOOR;
        }
    }
}

void Mg_Leaves_Update(Scene *scene)
{

    if (keys & J_A)
        SWEEPING_FLAG = 1;
    else
        SWEEPING_FLAG = 0;

    Mg_PlayerMovement(1, 0);

    check_leaf_status();
    check_leaf_collision();

    draw_actor(mg_player);

    return;
}