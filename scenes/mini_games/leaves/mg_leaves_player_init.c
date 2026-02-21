#pragma bank 2

#include "./mg_leaves.h"
#include "../../../include/position.h"
#include "../../../include/player.h"
#include "../../../include/render.h"
#include "../../../include/animation.h"
#include "../../../include/speed.h"
#include "../../../assets/sprites/mini_game/broom/broom.h"

void Mg_Leaves_Player_Init()
{
    position.x[mg_player] = 50;
    position.y[mg_player] = 104;
    speed[mg_player] = 400;

    position.fixed_x[mg_player] = position.x[mg_player] << 8;
    position.fixed_y[mg_player] = position.y[mg_player] << 8;

    render.tile_start[mg_player] = 0;
    render.tile_count[mg_player] = 2;
    render.vertical[mg_player] = TRUE;

    // PLAYER DOWN ANIMATIONS
    const unsigned char *broom_idle[] = {
        spr_broom_00,
        spr_broom_01};

    init_animation(mg_player, &animation[mg_player], 0, broom_idle, 1, DEFAULT_ANIMATION_SPEED, 2);
}