#pragma bank 1

#include "../../../include/inventory.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/position.h"
#include "../../../include/animation.h"
#include "../../../include/draw.h"
#include "../../../include/language.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/music.h"
#include "../../../include/money.h"

#include "../../../assets/chars/chars.h"
#include "../../../assets/sprites/frames/text_frame.h"

#include "../item_no_use.h"

#include "map_03.h"

void Map_03_CheckItems()
{
    if (active_item == 0)
        return;

    active_item = 0;

    if (CurrentMapData.event_active != 1)
    {
        ItemNoUseText();
        return;
    }

    uint8_t correct = 0;
    for (uint8_t i = 0; i < MAX_ITEMS; i++)
    {
        if (active_item_index == i && inventory[i].item == GLASSES)
        {
            correct = 1;
            inventory[i].item = ITM_NONE;
        }
    }

    if (correct == 0)
    {
        ItemNoUseText();
        return;
    }

    humor_stats[(uint8_t)NPC_ANTEOJOS] = 2;
    dialogue_phase[(uint8_t)NPC_ANTEOJOS] = 1;

    Map_03_InitDialogues();
    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ANTEOJOS, 0, 0, NONE);

    TextFrame_Init(12, 2);
    char *new_money;
    char *price = "$1500";

    if (language == SPANISH)
        new_money = "recibiste";
    else
        new_money = "you received";

    for (uint8_t i = 0; new_money[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(new_money[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 4, tile);
    }

    for (uint8_t i = 0; price[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(price[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 5, tile);
    }

    for (uint8_t i = 0; i < 180; i++)
        vsync();

    money += 1500;
    TextFrame_Close(12, 2);

    MiniGameWin();
}