#pragma bank 2

#include "map_11.h"

#include "../../inventory/inventory_scene.h"

#include "../../../include/player.h"
#include "../../../include/money.h"
#include "../../../include/market.h"
#include "../../../include/input.h"
#include "../../../include/position.h"
#include "../../../include/draw.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/text_positions.h"
#include "../../../include/language.h"

#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/buttons.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/frames/text_frame.h"

static void Map_11_ShowItems(uint8_t index, uint8_t *selected_state)
{
    uint8_t limit = index + 7;

    if (stock_items_count < limit)
        limit = stock_items_count;

    for (uint8_t i = index; i < limit; i++)
    {
        uint8_t y = 5 + (i - index);

        for (uint8_t j = 0; j < 10; j++)
        {
            if (stock_items[i] == items_info[j].item)
            {
                if (language == SPANISH)
                {
                    for (uint8_t k = 0; items_info[j].name_es[k] != '\0'; k++)
                    {
                        uint8_t tile = char_to_tile(items_info[j].name_es[k]) + CHARS_TILESET_START;
                        set_bkg_tile_xy(4 + k, y, tile);
                    }
                }
                else
                {
                    for (uint8_t k = 0; items_info[j].name_en[k] != '\0'; k++)
                    {
                        uint8_t tile = char_to_tile(items_info[j].name_en[k]) + CHARS_TILESET_START;
                        set_bkg_tile_xy(4 + k, y, tile);
                    }
                }

                uint8_t hundreds = (items_info[j].price / 100) + NUMBER_TILESET_START;
                uint8_t tens = ((items_info[j].price / 10) % 10) + NUMBER_TILESET_START;
                uint8_t units = (items_info[j].price % 10) + NUMBER_TILESET_START;

                set_bkg_tile_xy(15, y, hundreds);
                set_bkg_tile_xy(16, y, tens);
                set_bkg_tile_xy(17, y, units);

                break;
            }
        }

        if (selected_state[i] == 1)
        {
            uint8_t star_tile = char_to_tile('*') + CHARS_TILESET_START;
            set_bkg_tile_xy(3, y, star_tile);
        }
        else
        {
            set_bkg_tile_xy(3, y, 255);
        }

        uint8_t pr_symbol = char_to_tile('$') + CHARS_TILESET_START;
        set_bkg_tile_xy(14, y, pr_symbol);
    }
}

static void Map_11_ClearItems()
{
    for (uint8_t i = 0; i < 7; i++)
    {
        for (uint8_t j = 0; j < 15; j++)
        {
            uint8_t tile = 255;
            set_bkg_tile_xy(3 + j, 5 + i, tile); // Cambiado a 3 para limpiar la columna del asterisco
        }
    }
}

static void Map_11_Buy(uint8_t *selected_state)
{
    uint8_t new_count = 0;
    MarketItem temp_stock[10];

    MarketItem tmp_cart[10];
    uint8_t tmp_cart_count = 0;

    uint8_t y = 4;

    for (uint8_t i = 0; i < stock_items_count; i++)
    {
        if (selected_state[i] == 0)
        {
            temp_stock[new_count] = stock_items[i];
            new_count++;
        }
        else
        {
            tmp_cart[tmp_cart_count] = stock_items[i];
            tmp_cart_count++;
        }
    }

    for (uint8_t i = 0; i < new_count; i++)
    {
        stock_items[i] = temp_stock[i];
    }

    uint16_t total_price = 0;

    for (uint8_t i = 0; i < tmp_cart_count; i++)
    {
        for (uint8_t j = 0; j < 10; j++)
        {
            if (tmp_cart[i] == items_info[j].item)
                total_price += items_info[j].price;
        }
    }

    TextFrame_Init(13, 5);
    char *txt;
    uint8_t index;

    if (language == SPANISH)
        txt = "serian";
    else
        txt = "that'll be";

    for (index = 0; txt[index] != '\0'; index++)
    {
        char c = txt[index];
        uint8_t tile = char_to_tile(c) + CHARS_TILESET_START;
        set_bkg_tile_xy(2 + index, 5, tile);
    }

    uint8_t thousands = (total_price / 1000) + NUMBER_TILESET_START;
    uint8_t hundred = ((total_price / 100) % 10) + NUMBER_TILESET_START;
    uint8_t tens = ((total_price / 10) % 10) + NUMBER_TILESET_START;
    uint8_t units = (total_price % 10) + NUMBER_TILESET_START;

    uint8_t pr_symbol = char_to_tile('$') + CHARS_TILESET_START;
    set_bkg_tile_xy(2, 6, pr_symbol);
    set_bkg_tile_xy(3, 6, thousands);
    set_bkg_tile_xy(4, 6, hundred);
    set_bkg_tile_xy(5, 6, tens);
    set_bkg_tile_xy(6, 6, units);

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

    set_bkg_tile_xy(2, 8, b_button);

    for (uint8_t i = 0; back[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(back[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 8, tile);
    }

    set_bkg_tile_xy(2, 9, a_button);

    for (uint8_t i = 0; accept[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(accept[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 9, tile);
    }

    keys = 0;
    prev_keys = 0;

    while (1)
    {
        prev_keys = keys;
        keys = joypad();

        if (!(keys & J_B) && (prev_keys & J_B))
        {
            TextFrame_Close(13, 5);
            init_player();

            return;
        }

        if (!(keys & J_A) && (prev_keys & J_A))
        {
            TextFrame_Close(13, 5);

            init_player();

            if (money < total_price)
            {
                char *txt;
                if (language == SPANISH)
                    txt = "no me alcanza...";
                else
                    txt = "i don't have enough";

                for (uint8_t i = 0; txt[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y, tile);
                }

                return;
            }

            stock_items_count = new_count;

            for (uint8_t i = 0; i < tmp_cart_count; i++)
            {
                for (uint8_t j = 0; j < 10; j++)
                {
                    if (item_cart[j] == MKT_EMPTY)
                    {
                        item_cart[j] = tmp_cart[i];
                        player_items++;

                        break;
                    }
                }
            }

            TextFrame_Init(13, 2);
            char *txt;

            if (language == SPANISH)
                txt = "compra exitosa";
            else
                txt = "successful purchase";

            for (uint8_t i = 0; txt[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(2 + i, 5, tile);
            }

            for (uint8_t i = 0; i < 90; i++)
                vsync();

            TextFrame_Close(13, 2);
            money -= total_price;

            for (uint8_t i = 0; i < tmp_cart_count; i++)
            {
                if (tmp_cart[i] == MKT_BREAD)
                    NewItemScreen(BREAD);
            }

            return;
        }
    }
}

void Map_11_CheckInput()
{
    if (CurrentMapData.event_active == 0)
        return;

    if ((keys & J_A) && !(prev_keys & J_A))
    {
        cache_player_position();
        position.y[player] = 0;
        draw_actor(player);

        uint8_t items_selected_state[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        uint8_t total_selected_count = 0;

        char *title = "super";
        for (uint8_t i = 0; title[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(title[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }

        TextFrame_Init(14, 7);

        uint8_t index = 0;
        Map_11_ShowItems(index, items_selected_state);
        Map_11_InitOptionActor();

        keys = 0;
        prev_keys = 0;

        uint8_t selected_index = 0;
        uint8_t pos = 0;
        uint8_t tile_y = 5;

        while (1)
        {
            vsync();
            draw_actor(option_actor);

            prev_keys = keys;
            keys = joypad();

            tile_y = (position.y[option_actor] / 8) - 2;

            if (!(keys & J_RIGHT) && (prev_keys & J_RIGHT))
            {
                if (index == 7)
                    continue;

                pos = 0;
                position.y[option_actor] = 56;
                selected_index = 7;

                index = 7;
                Map_11_ClearItems();
                Map_11_ShowItems(index, items_selected_state);
            }

            if (!(keys & J_LEFT) && (prev_keys & J_LEFT))
            {
                if (index == 0)
                    continue;

                pos = 0;
                position.y[option_actor] = 56;
                selected_index = 0;

                index = 0;
                Map_11_ClearItems();
                Map_11_ShowItems(index, items_selected_state);
            }

            if (!(keys & J_UP) && (prev_keys & J_UP))
            {
                if (pos == 0)
                    continue;

                pos--;
                position.y[option_actor] -= 8;
                selected_index--;
            }

            if (!(keys & J_DOWN) && (prev_keys & J_DOWN))
            {
                if (pos == 6)
                    continue;

                if (selected_index + 1 >= stock_items_count)
                    continue;

                pos++;
                position.y[option_actor] += 8;
                selected_index++;
            }

            if (!(keys & J_A) && (prev_keys & J_A))
            {
                if (items_selected_state[selected_index] == 0)
                {
                    items_selected_state[selected_index] = 1;
                    total_selected_count++;
                }
                else
                {
                    items_selected_state[selected_index] = 0;
                    total_selected_count--;
                }

                Map_11_ShowItems(index, items_selected_state);
            }

            if (!(keys & J_B) && (prev_keys & J_B))
            {
                TextFrame_Close(14, 7);
                init_player();
                position.y[option_actor] = 0;
                draw_actor(option_actor);

                return;
            }

            if (!(keys & J_START) && (prev_keys & J_START))
            {
                TextFrame_Close(14, 7);

                position.y[option_actor] = 0;
                draw_actor(option_actor);

                Map_11_Buy(items_selected_state);
                return;
            }
        }
    }
}