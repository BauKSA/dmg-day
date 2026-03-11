#include <stddef.h>
#include <gb/gb.h>

#include "../npcs.h"
#include "../npc_lines.h"
#include "../name.h"
#include "../input.h"
#include "../scene_manager.h"
#include "../language.h"
#include "../entity.h"
#include "../../assets/sprites/frames/text_frame.h"
#include "../char_to_tile.h"
#include "../text_positions.h"
#include "../npc_stats_map.h"
#include "../../assets/chars/chars.h"
#include "../../assets/chars/numbers.h"
#include "../../assets/sprites/backgrounds/npc_icons/npc_icons.h"
#include "../../assets/chars/buttons.h"

#include "../../scenes/map/auto_clean.h"

Entity npc_1;
Entity npc_2;
Entity option_actor;

uint8_t humor_stats[MAX_NPCS];
uint8_t relation_stats[MAX_NPCS];

uint8_t dialogue_phase[MAX_NPCS];

void init_NPCs()
{
    npc_1 = create_entity();
    npc_2 = create_entity();
    option_actor = create_entity();
}

void Scene_DrawNPCLine(
    Entity npc,
    uint8_t npc_map,
    uint8_t npc_index,
    uint8_t has_minigame,
    enum AllScenes minigame)
{
    auto_clean_timer = 0;

    uint8_t relation = relation_stats[npc_map];
    uint8_t humor = humor_stats[npc_map];

    DialoguePerRelation *dialogue_ptr = CurrentNPCDialogues[npc_index];

    Line *first_line = &(*dialogue_ptr)[relation][humor][0];
    Line *second_line = &(*dialogue_ptr)[relation][humor][1];

    // Primera línea de diálogo
    for (size_t i = 0; (*first_line)[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile((*first_line)[i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + TEXT_START_X, TEXT_START_Y, 1, 1, &tile);
    }

    // Segunda línea de diálogo
    for (size_t i = 0; (*second_line)[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile((*second_line)[i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + TEXT_START_X, TEXT_START_Y + 1, 1, 1, &tile);
    }

    // Nombre
    for (size_t i = 0; names[npc][i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(names[npc][i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + NAME_START_X, NAME_START_Y, 1, 1, &tile);
    }

    // Humor
    uint8_t humor_icon_tile = humor_stats[npc_map] + NPC_ICONS_TILESET_START;
    set_bkg_tiles(HUMOR_ICON_X, ICON_Y, 1, 1, &humor_icon_tile);

    // Relación
    uint8_t relation_icon_tile = relation + NPC_ICONS_TILESET_START + 3;
    set_bkg_tiles(RELATION_ICON_X, ICON_Y, 1, 1, &relation_icon_tile);

    if (has_minigame)
    {
        TextFrame_Init(12, 1);

        uint8_t a_button = BUTTON_TILESET_START + 1;
        uint8_t b_button = BUTTON_TILESET_START + 2;

        if (language == SPANISH)
        {
            char txt[] = "ayudar?";
            for (uint8_t i = 0; txt[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + i, 4, tile);
            }

            char si[] = "si";
            char no[] = "no";

            for (uint8_t i = 0; si[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(si[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(13 + i, 6, tile);
            }

            set_bkg_tile_xy(12, 6, a_button);

            for (uint8_t i = 0; no[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(no[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(9 + i, 6, tile);
            }

            set_bkg_tile_xy(8, 6, b_button);
        }
        else if (language == ENGLISH)
        {
            char txt[] = "lend a hand?";
            for (uint8_t i = 0; txt[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(3 + i, 4, tile);
            }

            char si[] = "yes";
            char no[] = "no";

            for (uint8_t i = 0; si[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(si[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(12 + i, 6, tile);
            }

            set_bkg_tile_xy(11, 6, a_button);

            for (uint8_t i = 0; no[i] != '\0'; i++)
            {
                uint8_t tile = char_to_tile(no[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(8 + i, 6, tile);
            }

            set_bkg_tile_xy(7, 6, b_button);
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
                cache_player_position();
                next_scene = minigame;
                break;
            }

            if (!(keys & J_B) && (prev_keys & J_B))
            {
                dialogue_phase[npc_map] = 3; // fase única para ayudas denegadas
                humor_stats[npc_map] = 0;
                relation_stats[npc_map] = 0;

                TextFrame_Close(12, 1);

                break;
            }
        }
    }
}