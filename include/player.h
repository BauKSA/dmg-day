#pragma once

#include<stdint.h>

#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "position.h"
#include "render.h"
#include "load.h"
#include "animation.h"

// Player DOWN animation sprites
#include "../assets/sprites/player/girl/down/spr_Player_down0.h"
#include "../assets/sprites/player/girl/down/spr_Player_down1.h"
#include "../assets/sprites/player/girl/down/spr_Player_down2.h"

// Player UP animation sprites
#include "../assets/sprites/player/girl/up/spr_Player_up0.h"
#include "../assets/sprites/player/girl/up/spr_Player_up1.h"
#include "../assets/sprites/player/girl/up/spr_Player_up2.h"

extern Entity player;

typedef struct {
    uint8_t DOWN_STAY;
    uint8_t DOWN_WALKING;
    uint8_t UP_STAY;
    uint8_t UP_WALKING;
} PLAYER_ANIMATIONS;

extern PLAYER_ANIMATIONS player_animations;

uint8_t init_player(void);

#endif // PLAYER_H