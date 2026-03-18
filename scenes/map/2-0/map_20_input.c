#pragma bank 1

#include <gb/gb.h>

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/draw.h"
#include "../../../include/language.h"
#include "../../../include/money.h"
#include "../../../include/char_to_tile.h"

#include "../../../assets/chars/chars.h"
#include "../../../assets/sprites/frames/text_frame.h"
#include "../../../assets/chars/buttons.h"

#include "../map_data.h"
#include "map_20.h"

void Map_20_CheckInput()
{
    if (CurrentMapData.event_active == 0)
        return;

    if ((keys & J_A) && !(prev_keys & J_A))
    {
        cache_player_position();
        uint8_t npc_tmp_y = position.y[npc_1];

        position.y[npc_1] = 0;
        position.y[player] = 0;

        draw_actor(npc_1);
        draw_actor(player);

        TextFrame_Init(12, 4);

        uint8_t a_button = BUTTON_TILESET_START + 1;
        uint8_t b_button = BUTTON_TILESET_START + 2;

        if (language == SPANISH)
        {
            char txt[] = "comprar la";
            char txt_2[] = "guerra de";
            char txt_3[] = "los mundos";

            for (uint8_t i = 0; txt[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + i, 4, tile);
            }

            for (uint8_t i = 0; txt_2[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt_2[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(2 + i, 5, tile);
            }

            for (uint8_t i = 0; txt_3[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt_3[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(2 + i, 6, tile);
            }

            char si[] = "ayudar";
            char no[] = "irse";

            for (uint8_t i = 0; si[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(si[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(9 + i, 8, tile);
            }

            set_bkg_tile_xy(8, 8, a_button);

            for (uint8_t i = 0; no[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(no[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + i, 8, tile);
            }

            set_bkg_tile_xy(2, 8, b_button);
        }
        else if (language == ENGLISH)
        {
            char txt[] = "buy the war";
            char txt_2[] = "of the worlds";

            for (uint8_t i = 0; txt[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + i, 4, tile);
            }

            for (uint8_t i = 0; txt_2[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt_2[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(2 + i, 5, tile);
            }

            char si[] = "help";
            char no[] = "ignore";

            for (uint8_t i = 0; si[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(si[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(13 + i, 11, tile);
            }

            set_bkg_tile_xy(12, 11, a_button);

            for (uint8_t i = 0; no[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(no[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + i, 11, tile);
            }

            set_bkg_tile_xy(2, 11, b_button);
        }

        for (uint8_t i = 0; i < 15; i++)
            vsync();

        keys = 0;
        prev_keys = 0;

        while (1)
        {
            prev_keys = keys;
            keys = joypad();

            if (!(keys & J_A) && (prev_keys & J_A))
            {
                dialogue_phase[(uint8_t)NPC_LIBRO] = 2;
                relation_stats[(uint8_t)NPC_LIBRO] = 2;
                mission_20_active = 1;

                break;
            }

            if (!(keys & J_B) && (prev_keys & J_B))
            {
                dialogue_phase[(uint8_t)NPC_LIBRO] = 4;
                humor_stats[(uint8_t)NPC_LIBRO] = 0;
                relation_stats[(uint8_t)NPC_LIBRO] = 0;

                break;
            }
        }

        TextFrame_Close(12, 4);

        TextFrame_Init(12, 2);
        char *new_money;
        char *price = "$5250";

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

        for (uint8_t i = 0; i < 90; i++)
            vsync();

        money += 5250;
        TextFrame_Close(12, 2);

        init_player();
        position.y[npc_1] = npc_tmp_y;

        draw_actor(npc_1);
        draw_actor(player);

        Map_20_InitDialogues();

        vsync();
        clean();

        Scene_DrawNPCLine(npc_1, (uint8_t)NPC_LIBRO, 0, 0, NONE);
        npc_20_active = 0;

        return;
    }
}