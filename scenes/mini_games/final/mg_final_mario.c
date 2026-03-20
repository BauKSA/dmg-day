#pragma bank 6

#include <gb/gb.h>

#include "mg_final.h"

#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../../../include/draw.h"
#include "../../../include/input.h"
#include "../../../include/music.h"

#include "../../../assets/sprites/mini_game/mario/mario.h"

void Mg_Final_Mario()
{
    // MARIO
    position.x[npc_1] = 64;
    position.y[npc_1] = 96;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 1;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_mario0,

        // segundo frame
        spr_mario1};

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 2,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(npc_1);

    // BLOQUE
    position.x[npc_2] = 80;
    position.y[npc_2] = 80;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 1;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_block[] = {
        spr_block};

    init_animation(npc_2, &animation[npc_2], 0, npc_block, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(npc_2);

    uint8_t speed = 56;

    uint8_t timer = 0;
    uint8_t limit = 180;

    keys = 0;
    prev_keys = 0;

    uint8_t mario_win = 0;

    // Fisicas mínimas para el salto
    int16_t velocity_y = 0;
    uint8_t is_jumping = 0;
    const int16_t GRAVITY = 64;
    const int16_t JUMP = -1280;
    const uint8_t ground = 96;

    uint8_t mario_jump = 0;

    while (1)
    {
        vsync();

        prev_keys = keys;
        keys = joypad();

        position.fixed_x[npc_1] += speed;
        position.x[npc_1] = position.fixed_x[npc_1] >> 8;

        if ((keys & J_B) && !(prev_keys & J_B))
        {
            if (mario_jump == 1)
                continue;

            velocity_y = JUMP;
            is_jumping = 1;

            mario_jump = 1;
        }

        if (is_jumping)
        {
            position.fixed_y[npc_1] += velocity_y;
            velocity_y += GRAVITY;

            position.y[npc_1] = position.fixed_y[npc_1] >> 8;

            if (position.y[npc_1] >= ground)
            {
                position.y[npc_1] = ground;
                position.fixed_y[npc_1] = (uint16_t)ground << 8;
                is_jumping = 0;
                velocity_y = 0;
            }
        }

        if (is_jumping && position.y[npc_1] <= 88 && position.x[npc_1] >= 76 && position.x[npc_1] <= 88)
        {
            if (mario_win == 1)
                continue;

            mario_win = 1;

            position.y[npc_1] = 89;
            position.fixed_y[npc_1] = (uint16_t)89 << 8;

            velocity_y = 256;

            NR10_REG = 0x16;
            NR11_REG = 0x40;
            NR12_REG = 0x73;
            NR13_REG = 0x00;
            NR14_REG = 0xC3;
        }

        update_animation(&animation[npc_1]);
        draw_actor(npc_1);

        timer++;

        if (timer >= limit)
            break;
    }

    if (mario_win == 1)
    {
        current_game++;
        wins++;

        MiniGameWin();
    }
    else
    {
        current_game++;
        MiniGameLose();
    }
}