#pragma bank 3
#include <gb/gb.h>

#include "map_23.h"
#include "../map_data.h"

#include "../../inventory/inventory_scene.h"

#include "../../../include/char_to_tile.h"
#include "../../../include/language.h"
#include "../../../include/draw.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/text_positions.h"
#include "../../../include/scene_manager.h"
#include "../../../include/npcs.h"
#include "../../../include/money.h"
#include "../../../include/player.h"
#include "../../../include/input.h"

#include "../../../assets/sprites/frames/text_frame.h"
#include "../../../assets/sprites/backgrounds/maps/2-3/map_2-3.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/chars/buttons.h"

void Map_23_ShowBooks()
{
    TextFrame_Init(13, 4);

    Book books[4];

    uint8_t selected = 0;

    if (language == SPANISH)
    {
        books[0].line_a = " orgullo y";
        books[0].line_b = "prejuicio";

        books[1].line_a = " el hobbit";
        books[1].line_b = "\0";

        books[2].line_a = " la guerra de";
        books[2].line_b = "los mundos";

        books[3].line_a = " martin fierro";
        books[3].line_b = "\0";
    }
    else
    {
        books[2].line_a = " the war of";
        books[2].line_b = "the worlds";

        books[1].line_a = " the hobbit";
        books[1].line_b = "\0";

        books[0].line_a = " pride and";
        books[0].line_b = "prejudice";

        books[3].line_a = " martin fierro";
        books[3].line_b = "\0";
    }

    books[0].book = PRIDE;
    books[1].book = HOBBIT;
    books[2].book = WAR;
    books[3].book = FIERRO;

    books[0].price = 4500;
    books[1].price = 3000;
    books[2].price = 5250;
    books[3].price = 6000;

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
    position.y[option_actor] = 48;

    position.fixed_x[option_actor] = position.x[option_actor];
    position.fixed_y[option_actor] = position.y[option_actor];

    render.tile_start[option_actor] = 0;
    render.tile_count[option_actor] = 1;
    render.vertical[option_actor] = TRUE;

    const unsigned char *arrow_idle[] = {spr_RightArrow};

    init_animation(option_actor, &animation[option_actor], 0, arrow_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    keys = 0;
    prev_keys = 0;

    while (1)
    {
        vsync();
        draw_actor(option_actor);

        prev_keys = keys;
        keys = joypad();

        if ((keys & J_UP) && !(prev_keys & J_UP))
        {
            if (selected == 0)
                continue;

            selected--;

            uint8_t movement = 8;
            if (selected == 0 || selected == 2)
                movement += 8;

            position.y[option_actor] -= movement;
        }

        if ((keys & J_DOWN) && !(prev_keys & J_DOWN))
        {
            if (selected == 3)
                continue;

            selected++;

            uint8_t movement = 8;
            if (selected == 1 || selected == 3)
                movement += 8;

            position.y[option_actor] += movement;
        }

        if (!(keys & J_A) && (prev_keys & J_A))
            break;
    }

    TextFrame_Close(13, 4);

    position.y[option_actor] = 0;
    draw_actor(option_actor);

    TextFrame_Init(13, 4);
    char *txt;
    uint8_t index;

    if (language == SPANISH)
        txt = "serian $";
    else
        txt = "that'll be $";

    for (index = 0; txt[index] != '\0'; index++)
    {
        char c = txt[index];
        uint8_t tile = char_to_tile(c) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + index, y - 1, tile);
    }

    uint8_t thousands = (books[selected].price / 1000) + NUMBER_TILESET_START;
    uint8_t hundred = ((books[selected].price / 100) % 10) + NUMBER_TILESET_START;
    uint8_t tens = ((books[selected].price / 10) % 10) + NUMBER_TILESET_START;
    uint8_t units = (books[selected].price % 10) + NUMBER_TILESET_START;

    set_bkg_tile_xy(3 + index, y - 1, thousands);
    index++;
    set_bkg_tile_xy(3 + index, y - 1, hundred);
    index++;
    set_bkg_tile_xy(3 + index, y - 1, tens);
    index++;
    set_bkg_tile_xy(3 + index, y - 1, units);
    index++;

    char *accept;
    char *back;

    if (language == SPANISH)
    {
        accept = "aceptar";
        back = "volver";
    }
    else
    {
        accept = "accept";
        back = "back";
    }

    uint8_t b_button = BUTTON_TILESET_START + 2;
    uint8_t a_button = BUTTON_TILESET_START + 1;

    set_bkg_tile_xy(3, y + 1, b_button);

    for (uint8_t i = 0; back[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(back[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(4 + i, y + 1, tile);
    }

    set_bkg_tile_xy(3, y + 2, a_button);

    for (uint8_t i = 0; accept[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(accept[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(4 + i, y + 2, tile);
    }

    keys = 0;
    prev_keys = 0;

    while (1)
    {
        prev_keys = keys;
        keys = joypad();

        if (!(keys & J_B) && (prev_keys & J_B))
        {
            back = 1;
            break;
        }

        if ((keys & J_A) && !(prev_keys & J_A))
        {
            if (money < books[selected].price)
            {
                char *no_money;

                clean();

                if (language == SPANISH)
                    no_money = "no me alcanza...";
                else
                    no_money = "i don't have enough";

                for (uint8_t i = 0; no_money[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(no_money[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y, tile);
                }

                break;
            }

            dialogue_phase[(uint8_t)NPC_DIARIO]++;

            purchased_book = books[selected].book;
            money -= books[selected].price;

            NewItemScreen(BOOK);
            next_scene = INVENTORY;

            break;
        }
    }

    TextFrame_Close(13, 4);
}