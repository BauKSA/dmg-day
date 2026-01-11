#pragma once

#include<stdint.h>

#include "entity.h"
#include "position.h"
#include "render.h"
#include "load.h"

#include "../assets/sprites/player/spr_Player_down0.c"
#include "../assets/sprites/player/spr_Player_down1.c"
#include "../assets/sprites/player/spr_Player_down2.c"

#include "../assets/sprites/player/spr_Player_up0.c"
#include "../assets/sprites/player/spr_Player_up1.c"
#include "../assets/sprites/player/spr_Player_up2.c"

Entity player;

typedef struct {
    uint8_t DOWN_STAY;
    uint8_t DOWN_WALKING;
    uint8_t UP_STAY;
    uint8_t UP_WALKING;
} PLAYER_ANIMATIONS;

PLAYER_ANIMATIONS player_animations;

uint8_t init_player()
{
    player = create_entity();

    position.x[player] = 20;
    position.y[player] = 20;

    position.fixed_x[player] = position.x[player] << 8;
    position.fixed_y[player] = position.y[player] << 8;

    render.tile_start[player] = 0;
    render.tile_count[player] = 4;
    render.vertical[player] = TRUE;

    //PLAYER DOWN ANIMATIONS
    const unsigned char *player_down_stay[] = {
        spr_Player_down1_00,
        spr_Player_down1_01,
        spr_Player_down1_10,
        spr_Player_down1_11};

    const unsigned char *player_down_walking[] = {
        // primer frame
        spr_Player_down0_00,
        spr_Player_down0_01,
        spr_Player_down0_10,
        spr_Player_down0_11,
        // segundo frame
        spr_Player_down1_00,
        spr_Player_down1_01,
        spr_Player_down1_10,
        spr_Player_down1_11,
        // tercer frame
        spr_Player_down2_00,
        spr_Player_down2_01,
        spr_Player_down2_10,
        spr_Player_down2_11,
        // cuarto frame
        spr_Player_down1_00,
        spr_Player_down1_01,
        spr_Player_down1_10,
        spr_Player_down1_11};

    //PLAYER UP ANIMATIONS
        const unsigned char *player_up_stay[] = {
        spr_Player_up1_00,
        spr_Player_up1_01,
        spr_Player_up1_10,
        spr_Player_up1_11};

    const unsigned char *player_up_walking[] = {
        // primer frame
        spr_Player_up0_00,
        spr_Player_up0_01,
        spr_Player_up0_10,
        spr_Player_up0_11,
        // segundo frame
        spr_Player_up1_00,
        spr_Player_up1_01,
        spr_Player_up1_10,
        spr_Player_up1_11,
        // tercer frame
        spr_Player_up2_00,
        spr_Player_up2_01,
        spr_Player_up2_10,
        spr_Player_up2_11,
        // cuarto frame
        spr_Player_up1_00,
        spr_Player_up1_01,
        spr_Player_up1_10,
        spr_Player_up1_11};

    init_animation(player, &animation[player], 0, player_down_stay, 1, DEFAULT_ANIMATION_SPEED, 4);
    init_animation(player, &animation[player], 1, player_down_walking, 4, DEFAULT_ANIMATION_SPEED, 4);
    init_animation(player, &animation[player], 2, player_up_stay, 1, DEFAULT_ANIMATION_SPEED, 4);
    init_animation(player, &animation[player], 3, player_up_walking, 4, DEFAULT_ANIMATION_SPEED, 4);

    player_animations.DOWN_STAY = 0;
    player_animations.DOWN_WALKING = 1;
    player_animations.UP_STAY = 2;
    player_animations.UP_WALKING = 3;

    return player;
}