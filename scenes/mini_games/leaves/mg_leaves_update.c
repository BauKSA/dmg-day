#include "./mg_leaves.h"
#include "../mg_player_movement.h"
#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/extra_actor.h"
#include "../../../include/random.h"

void check_leaf_status()
{
    for (uint8_t i = 0; i <= extra_actor_index; i++)
    {
        uint8_t offset = i * 8;
        if (leaf_active[i] == 0)
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

        if (leaf_y[i] >= 112)
            leaf_state[i] = ON_FLOOR;

        draw_extra(leaf_ids[i], leaf_x[i] + offset, leaf_y[i], 1, 1);
    }
}

void Mg_Leaves_Update(Scene *scene)
{
    Mg_PlayerMovement(1, 0);

    check_leaf_status();

    draw_actor(mg_player);

    return;
}