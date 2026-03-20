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

#include "../../../assets/sprites/mini_game/metroid/metroid.h"

void Mg_Final_Metroid() BANKED
{
    // Samus
    position.x[npc_1] = 68;
    position.y[npc_1] = 96;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 1;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_samus};

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    set_animation(&animation[npc_1], 0);

    draw_actor(npc_1);

    // Metroid
    position.x[npc_2] = 88;
    position.y[npc_2] = 96;

    position.fixed_x[npc_2] = position.x[npc_2] << 8;
    position.fixed_y[npc_2] = position.y[npc_2] << 8;

    render.tile_start[npc_2] = 0;
    render.tile_count[npc_2] = 1;
    render.vertical[npc_2] = TRUE;

    const unsigned char *npc_metroid[] = {
        spr_metroid0};

    const unsigned char *npc_metroid_iced[] = {
        spr_metroid1};

    init_animation(npc_2, &animation[npc_2], 0, npc_metroid, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    init_animation(npc_2, &animation[npc_2], 1, npc_metroid_iced, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(npc_2);

    // Missile
    position.x[option_actor] = 68;
    position.y[option_actor] = 96;

    position.fixed_x[option_actor] = position.x[option_actor] << 8;
    position.fixed_y[option_actor] = position.y[option_actor] << 8;

    render.tile_start[option_actor] = 0;
    render.tile_count[option_actor] = 1;
    render.vertical[option_actor] = TRUE;

    const unsigned char *npc_missile[] = {
        spr_missile};

    init_animation(option_actor, &animation[option_actor], 0, npc_missile, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    uint8_t speed = 120;

    uint8_t timer = 0;
    uint8_t limit = 180;

    keys = 0;
    prev_keys = 0;

    uint8_t iced = 0;
    uint8_t shoot = 0;
    uint8_t miss = 0;

    uint8_t up = 1;
    uint8_t metroid_dist = 0;
    const uint8_t METROID_MAX_DIST = 16;

    while (1)
    {
        vsync();

        prev_keys = keys;
        keys = joypad();

        if (iced == 0)
        {
            if (timer % 2 == 0)
            {
                if (up == 1)
                    position.y[npc_2] -= 1;
                else
                    position.y[npc_2] += 1;

                metroid_dist++;

                if (metroid_dist >= METROID_MAX_DIST)
                {
                    if (up == 1)
                        up = 0;
                    else
                        up = 1;

                    metroid_dist = 0;
                }
            }
        }

        if (shoot == 1 && iced == 0 && miss == 0)
        {
            position.fixed_x[option_actor] += speed;
            position.x[option_actor] = position.fixed_x[option_actor] >> 8;

            draw_actor(option_actor);

            if (position.x[option_actor] >= position.x[npc_2])
            {
                if (position.y[option_actor] >= position.y[npc_2] &&
                    position.y[option_actor] <= position.y[npc_2] + 8)
                {
                    iced = 1;

                    NR10_REG = 0x16;
                    NR11_REG = 0x40;
                    NR12_REG = 0x73;
                    NR13_REG = 0x00;
                    NR14_REG = 0xC3;

                    set_animation(&animation[npc_2], 1);
                    position.y[option_actor] = 0;
                    draw_actor(option_actor);
                }
                else
                {
                    miss = 1;
                    position.y[option_actor] = 0;
                    draw_actor(option_actor);
                }
            }
        }

        if ((keys & J_B) && !(prev_keys & J_B))
        {
            if (shoot == 0)
                shoot = 1;
        }

        draw_actor(npc_1);
        draw_actor(npc_2);

        if (miss == 0 && iced == 0 && shoot == 0)
            draw_actor(option_actor);

        timer++;

        if (timer >= limit)
            break;
    }

    if (iced == 1)
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