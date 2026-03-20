#pragma bank 5

#include "map_33.h"

#include <gb/gb.h>

#include "../../../include/market.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/language.h"
#include "../../../include/money.h"
#include "../../../include/mgm_states.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/music.h"

#include "../../../assets/sprites/frames/text_frame.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"

void Map_33_Deliver()
{
    uint8_t target_deliver = 4;
    uint8_t deliver_items = 0;
    uint16_t total_price = 0;

    uint8_t item_used[10] = {0};

    for (uint8_t i = 0; i < ITEMS_TO_BUY; i++)
    {
        for (uint8_t j = 0; j < 10; j++)
        {
            if (!item_used[j] && items_to_buy[i] == item_cart[j])
            {
                deliver_items++;
                item_used[j] = 1;

                for (uint8_t k = 0; k < 10; k++)
                {
                    if (items_to_buy[i] == items_info[k].item)
                    {
                        total_price += items_info[k].price;
                        break;
                    }
                }

                break;
            }
        }
    }

    uint8_t npc_map = (uint8_t)NPC_SUPER;
    uint16_t reward = 0;
    dialogue_phase[npc_map] = 4;

    if (deliver_items == 0)
    {
        humor_stats[npc_map] = 0;
        relation_stats[npc_map] = 0;

        DeclineHelp();
    }
    else if (deliver_items < target_deliver)
    {
        humor_stats[npc_map] = 0;
        reward = total_price + (total_price / 2);
    }
    else
    {
        humor_stats[npc_map] = 2;
        relation_stats[npc_map] = 2;
        reward = total_price + 2500;

        MiniGameWin();
    }

    Map_33_InitDialogues();
    Scene_DrawNPCLine(npc_1, npc_map, 0, 0, NONE);

    TextFrame_Init(12, 2);
    char *new_money;

    if (language == SPANISH)
        new_money = "recibiste";
    else
        new_money = "you received";

    for (uint8_t i = 0; new_money[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(new_money[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 4, tile);
    }

    uint8_t digits[5];
    uint16_t tmp_reward = reward;

    for (uint8_t i = 5; i >= 1; i--)
    {
        digits[i - 1] = tmp_reward % 10;
        tmp_reward /= 10;
    }

    uint8_t tile_symbol = char_to_tile('$') + CHARS_TILESET_START;
    set_bkg_tile_xy(3, 5, tile_symbol);

    for (uint8_t i = 0; i < 5; i++)
    {
        uint8_t tile = digits[i] + NUMBER_TILESET_START;
        set_bkg_tile_xy(4 + i, 5, tile);
    }

    for (uint8_t i = 0; i < 180; i++)
        vsync();

    EarnMoney();

    money += reward;
    TextFrame_Close(12, 2);

    MGM_states.super = MGM_INACTIVE;
}