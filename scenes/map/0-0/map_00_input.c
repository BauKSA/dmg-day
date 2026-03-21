#pragma bank 1

#include <gb/gb.h>

#include "map_00.h"

#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
#include "../../../include/input.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/scene_manager.h"
#include "../../../include/position.h"
#include "../../../include/mgm_states.h"
#include "../../../include/music.h"
#include "../../../include/text_positions.h"
#include "../../../include/money.h"

#include "../../../assets/chars/buttons.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/sprites/frames/text_frame.h"

#include "../map_data.h"

void Map_00_CheckInput()
{
    if (CurrentMapData.event_active == 0)
        return;

    if (!(keys & J_A) && (prev_keys & J_A))
    {
        Scene_DrawNPCLine(npc_1, (uint8_t)NPC_TIENDA, 0, 0, NONE);

        TextFrame_Init(12, 2);

        char *accept;
        char *decline;

        if (language == SPANISH)
        {
            accept = "comprar!";
            decline = "todavia no";
        }
        else
        {
            accept = "buy it!";
            decline = "not yet";
        }

        uint8_t a_button = BUTTON_TILESET_START + 1;
        uint8_t b_button = BUTTON_TILESET_START + 2;

        set_bkg_tile_xy(2, 5, a_button);
        set_bkg_tile_xy(2, 6, b_button);

        for (uint8_t i = 0; accept[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(accept[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(4 + i, 5, tile);
        }

        for (uint8_t i = 0; decline[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(decline[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(4 + i, 6, tile);
        }

        keys = 0;
        prev_keys = 0;

        while (1)
        {
            vsync();

            prev_keys = keys;
            keys = joypad();

            if (!(keys & J_B) && (prev_keys & J_B))
            {
                TextFrame_Close(12, 2);
                break;
            }

            if (!(keys & J_A) && (prev_keys & J_A))
            {
                TextFrame_Close(12, 2);

                if (money < GAME_BOY_PRICE)
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

                TextFrame_Init(14, 7);

                char *line_a;
                char *line_b;
                char *line_c;
                char *line_d;
                char *line_e;
                char *line_f;
                char *line_g;
                char *line_h;

                if (language == SPANISH)
                {
                    char *line_a = "bien... pero yo";
                    char *line_b = "no le vendo a";
                    char *line_c = "cualquiera.";
                    char *line_d = "tenes que";
                    char *line_e = "demostrar lo";
                    char *line_f = "que sabes y ser";
                    char *line_g = "digna de tener";
                    char *line_h = "la consola...";
                }
                else
                {
                    char *line_a = "fine... but I";
                    char *line_b = "do not sell to";
                    char *line_c = "just anyone.";
                    char *line_d = "you must";
                    char *line_e = "prove your";
                    char *line_f = "worth and be";
                    char *line_g = "worthy of the";
                    char *line_h = "console...";
                }

                for (uint8_t i = 0; line_a[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_a[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 4, tile);
                }

                for (uint8_t i = 0; line_b[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_b[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 5, tile);
                }

                for (uint8_t i = 0; line_c[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_c[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 6, tile);
                }

                for (uint8_t i = 0; line_d[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_d[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 7, tile);
                }

                for (uint8_t i = 0; line_e[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_e[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 8, tile);
                }

                for (uint8_t i = 0; line_f[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_f[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 9, tile);
                }

                for (uint8_t i = 0; line_g[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_g[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 10, tile);
                }

                for (uint8_t i = 0; line_h[i] != '\0'; i++)
                {
                    uint8_t tile = char_to_tile(line_h[i]) + CHARS_TILESET_START;
                    set_bkg_tile_xy(2 + i, 11, tile);
                }

                for (uint8_t i = 0; i < 120; i++)
                    vsync();

                next_scene = MG_FINAL;
            }
        }
    }
}
