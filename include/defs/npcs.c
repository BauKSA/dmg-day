#include <stddef.h>
#include <gb/gb.h>

#include "../npcs.h"
#include "../npc_lines.h"
#include "../name.h"
#include "../entity.h"
#include "../char_to_tile.h"
#include "../text_positions.h"
#include "../npc_stats_map.h"
#include "../../assets/chars/chars.h"
#include "../../assets/chars/numbers.h"

Entity npc_1;
Entity npc_2;
Entity option_actor;

uint8_t humor_stats[MAX_NPCS];

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
    uint8_t relation = 1;
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
        set_bkg_tiles(i + TEXT_START_X, TEXT_START_Y, 1, 1, &tile);
    }

    // Nombre
    for (size_t i = 0; names[npc][i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(names[npc][i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + NAME_START_X, NAME_START_Y, 1, 1, &tile);
    }

    // Humor
    uint8_t humor_icon_tile = humor_stats[npc_map] + NUMBER_TILESET_START;
    set_bkg_tiles(HUMOR_ICON_X, ICON_Y, 1, 1, &humor_icon_tile);
}