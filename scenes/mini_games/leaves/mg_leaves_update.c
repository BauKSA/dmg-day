#pragma bank 2

#include <gb/gb.h>

#include "./mg_leaves.h"
#include "../mg_player_movement.h"
#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/extra_actor.h"
#include "../../../include/random.h"
#include "../../../include/collision.h"
#include "../../../include/input.h"

void check_actor_status()
{
    for (uint8_t i = 0; i <= extra_actor_index; i++)
    {
        if (actor_active[i] == 0 && actor_state[i] == FALLING)
        {
            if ((my_rand() % 400) == 0)
            {
                actor_active[i] = 1;
                actor_timer[i] = 0;
                actor_y[i] = 24;

                continue;
            }

            continue;
        }

        if (actor_state[i] == FALLING)
            actor_y[i]++;

        if (actor_y[i] >= mg_leaves_DATA.bottom_limit && actor_state[i] == FALLING)
            actor_state[i] = ON_FLOOR;

        if (SWEEPING_FLAG)
        {
            if (actor_x[i] >= mg_leaves_DATA.right_limit && actor_state[i] == BEING_SWEPT_LEFT)
            {
                actor_state[i] = FALLING;
                actor_active[i] = 0;
                actor_y[i] = 0;

                seed = LY_REG;
                seed |= (unsigned int)DIV_REG << 8;
                
                uint8_t spawn_x = my_rand() % LEAF_COUNT;

                actor_x[i] = actor_spawn_x[spawn_x];
            }
        }

        if (actor_state[i] == BEING_SWEPT_RIGHT && SWEEPING_FLAG)
            actor_x[i] = position.x[mg_player] - 8;

        if (actor_state[i] == BEING_SWEPT_LEFT && SWEEPING_FLAG)
            actor_x[i] = position.x[mg_player] + 8;

        draw_extra(actor_ids[i], actor_x[i], actor_y[i], 1, 1);
    }
}

void check_actor_collision()
{
    uint8_t x1 = position.x[mg_player];

    for (uint8_t i = 0; i < LEAF_COUNT; i++)
    {
        if (actor_state[i] == FALLING)
            continue;

        uint8_t x2 = actor_x[i];

        if (x1 < x2 + 8 && x1 + 4 > x2)
        {
            if (x1 > x2)
                actor_state[i] = BEING_SWEPT_RIGHT;

            if (x2 > x1)
                actor_state[i] = BEING_SWEPT_LEFT;
        }
        else
        {
            actor_state[i] = ON_FLOOR;
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

    check_actor_status();
    check_actor_collision();

    draw_actor(mg_player);

    return;
}