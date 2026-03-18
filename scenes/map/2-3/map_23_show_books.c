#pragma bank 3
#include <gb/gb.h>

#include "map_23.h"

#include "../../../include/char_to_tile.h"
#include "../../../include/language.h"
#include "../../../include/draw.h"
#include "../../../assets/sprites/frames/text_frame.h"
#include "../../../assets/sprites/backgrounds/maps/2-3/map_2-3.h"
#include "../../../assets/chars/chars.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"

void Map_23_ShowBooks()
{
    TextFrame_Init(13, 4);

    Book books[4];

    if (language == SPANISH)
    {
        books[2].line_a = " la guerra de";
        books[2].line_b = "los mundos";

        books[1].line_a = "  el hobbit";
        books[1].line_b = "\0";

        books[0].line_a = " orgullo y";
        books[0].line_b = "prejuicio";

        books[3].line_a = " martin fierro";
        books[3].line_b = "\0";
    }
    else
    {
        books[2].line_a = " the war of";
        books[2].line_a = " the worlds";

        books[1].line_a = " the hobbit";
        books[1].line_b = "\0";

        books[0].line_a = " pride and";
        books[0].line_b = " prejudice";

        books[3].line_a = " martin fierro";
        books[3].line_b = "\0";
    }

    books[0].book = PRIDE;
    books[1].book = HOBBIT;
    books[2].book = WAR;
    books[3].book = FIERRO;

    books[0].price = 100;
    books[1].price = 200;
    books[2].price = 150;
    books[3].price = 175;

    uint8_t y = 4;

    for (uint8_t i = 0; i < 4; i++)
    {
        for (uint8_t j = 0; books[i].line_a[j] != '\0'; j++)
        {
            char c = books[i].line_a[j];
            uint8_t tile = char_to_tile(c) + CHARS_TILESET_START;
            set_bkg_tile_xy(3 + j, y + i, tile);
        }

        if (books[i].line_b[0] != '\0')
        {
            y++;
            for (uint8_t k = 0; books[i].line_b[k] != '\0'; k++)
            {
                char c = books[i].line_b[k];
                uint8_t tile = char_to_tile(c) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + k, y + i, tile);
            }
        }
    }

    cache_player_position();
    position.y[player] = 0;
    position.y[npc_1] = 0;

    draw_actor(player);
    draw_actor(npc_1);

    position.x[option_actor] = 32;
    position.y[option_actor] = 72;

    position.fixed_x[option_actor] = position.x[option_actor];
    position.fixed_y[option_actor] = position.y[option_actor];

    render.tile_start[option_actor] = 0;
    render.tile_count[option_actor] = 1;
    render.vertical[option_actor] = TRUE;

    const unsigned char *arrow_idle[] = {spr_RightArrow};

    init_animation(option_actor, &animation[option_actor], 0, arrow_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    draw_actor(option_actor);

    while (1)
    {
        vsync();
    }
}