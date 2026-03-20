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

#include "../../../assets/sprites/mini_game/tetris/tetris.h"

void Mg_Final_Tetris()
{
    position.x[npc_1] = 80;
    position.y[npc_1] = 64;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 2;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_tetris00,
        spr_tetris01};

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                   DEFAULT_ANIMATION_SPEED, 2);

    draw_actor(npc_1);

    uint8_t speed = 35;

    uint8_t timer = 0;
    uint8_t limit = 180;

    keys = 0;
    prev_keys = 0;

    while (1)
    {
        vsync();

        prev_keys = keys;
        keys = joypad();

        if ((keys & J_LEFT) && !(prev_keys & J_LEFT))
        {
            position.x[npc_1] -= 4;
            if (position.x[npc_1] < 64)
                position.x[npc_1] = 64;
        }

        if ((keys & J_RIGHT) && !(prev_keys & J_RIGHT))
        {
            position.x[npc_1] += 4;
            if (position.x[npc_1] > 96)
                position.x[npc_1] = 96;
        }

        position.fixed_y[npc_1] += speed;
        position.y[npc_1] = position.fixed_y[npc_1] >> 8;

        if (position.y[npc_1] == 76 && position.x[npc_1] != 96)
            break;

        draw_actor(npc_1);

        timer++;

        if (timer >= limit)
            break;
    }

    if (position.x[npc_1] == 96)
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

    uint8_t empty_tile = 255;

    for (uint8_t i = 8; i <= 11; i++)
    {
        set_bkg_tile_xy(i, 9, empty_tile);
        set_bkg_tile_xy(i, 10, empty_tile);
    }

    position.y[npc_1] = 0;
    draw_actor(npc_1);
}