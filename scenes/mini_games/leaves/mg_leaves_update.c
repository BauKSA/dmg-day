#include "./mg_leaves.h"
#include "../mg_player_movement.h"
#include "../../../include/draw.h"
#include "../../../include/player.h"
#include "../../../include/extra_actor.h"

void Mg_Leaves_Update(Scene *scene)
{
    Mg_PlayerMovement();
    draw_extra(extra_actor_index, 50, 50, 1, 1);
    draw_actor(mg_player);
    
    return;
}