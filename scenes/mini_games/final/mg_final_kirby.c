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

#include "../../../assets/sprites/mini_game/kirby/kirby.h"

void Mg_Final_Kirby()
{
    // Kirby
    position.x[npc_1] = 68;
    position.y[npc_1] = 96;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 1;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_kirby0};

    const unsigned char *npc_sprite_b[] = {
        // primer frame
        spr_kirby1};

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    init_animation(npc_1, &animation[npc_1], 1, npc_sprite_b, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(npc_1);

    // BLOQUE
    position.x[npc_2] = 96;
    position.y[npc_2] = 96;

    position.fixed_x[npc_2] = position.x[npc_2] << 8;
    position.fixed_y[npc_2] = position.y[npc_2] << 8;

    render.tile_start[npc_2] = 0;
    render.tile_count[npc_2] = 1;
    render.vertical[npc_2] = TRUE;

    const unsigned char *npc_star[] = {
        spr_kirby_star};

    init_animation(npc_2, &animation[npc_2], 0, npc_star, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(npc_2);

    uint8_t speed = 64;

    uint8_t timer = 0;
    uint8_t limit = 180;

    keys = 0;
    prev_keys = 0;

    uint8_t star_eaten = 0;
    uint8_t eating = 0;

    while (1)
    {
        vsync();

        prev_keys = keys;
        keys = joypad();

        if (eating == 1)
        {
            position.fixed_x[npc_2] -= speed;
            position.x[npc_2] = position.fixed_x[npc_2] >> 8;
        }

        if (position.x[npc_2] <= position.x[npc_1])
        {
            position.y[npc_2] = 0;
            star_eaten = 1;

            NR10_REG = 0x16;
            NR11_REG = 0x40;
            NR12_REG = 0x73;
            NR13_REG = 0x00;
            NR14_REG = 0xC3;
        }

        if ((keys & J_B) && !(prev_keys & J_B))
        {
            set_animation(&animation[npc_1], 1);
            eating = 1;
        }

        if (!(keys & J_B) && (prev_keys & J_B))
        {
            set_animation(&animation[npc_1], 0);
            eating = 0;
        }

        draw_actor(npc_2);
        draw_actor(npc_1);

        timer++;

        if (timer >= limit)
            break;
    }

    if (star_eaten == 1)
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