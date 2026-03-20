#pragma bank 7

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

#include "../../../assets/sprites/mini_game/zelda/zelda.h"

void Mg_Final_Zelda() BANKED
{
    // Link
    position.x[npc_1] = 80;
    position.y[npc_1] = 80;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 1;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_link0};

    const unsigned char *npc_sprite_attack[] = {
        // primer frame
        spr_link1, spr_link1b};

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    init_animation(npc_1, &animation[npc_1], 1, npc_sprite, 2,
                   DEFAULT_ANIMATION_SPEED / 2, 1);

    draw_actor(npc_1);

    // Arbusto / rupia
    position.x[npc_2] = 96;
    position.y[npc_2] = 80;

    position.fixed_x[npc_2] = position.x[npc_2] << 8;
    position.fixed_y[npc_2] = position.y[npc_2] << 8;

    render.tile_start[npc_2] = 0;
    render.tile_count[npc_2] = 1;
    render.vertical[npc_2] = TRUE;

    const unsigned char *npc_grass[] = {
        spr_grass};

    const unsigned char *npc_rupia[] = {
        spr_rupia};

    init_animation(npc_2, &animation[npc_2], 0, npc_grass, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    init_animation(npc_2, &animation[npc_2], 1, npc_rupia, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(npc_2);

    uint8_t speed = 64;

    uint8_t timer = 0;
    uint8_t limit = 180;

    uint8_t anim_rate = 15;

    keys = 0;
    prev_keys = 0;

    uint8_t attack = 0;
    uint8_t win = 0;

    while (1)
    {
        vsync();

        prev_keys = keys;
        keys = joypad();

        if (keys & J_RIGHT)
        {
            position.fixed_x[npc_1] += speed;
            position.x[npc_1] = position.fixed_x[npc_1] >> 8;
        }

        if (!(keys & J_B) && (prev_keys & J_B))
        {
            if (attack == 1)
                continue;

            attack = 1;

            set_animation(&animation[npc_1], 1);

            if (position.x[npc_1] > 88)
            {
                win = 1;

                set_animation(&animation[npc_2], 1);

                NR10_REG = 0x16;
                NR11_REG = 0x40;
                NR12_REG = 0x73;
                NR13_REG = 0x00;
                NR14_REG = 0xC3;
            }
        }

        update_animation(&animation[npc_1]);
        update_animation(&animation[npc_2]);

        draw_actor(npc_1);
        draw_actor(npc_2);

        timer++;

        if (attack == 1)
        {
            if (anim_rate != 0)
            {
                anim_rate--;
                if (anim_rate == 0)
                {
                    set_animation(&animation[npc_1], 0);
                }
            }
        }

        if (timer >= limit)
            break;
    }

    if (win == 1)
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