#include <stddef.h>
#include <gb/gb.h>

#include "../npcs.h"
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
    char first_line[18],
    char second_line[18],
    uint8_t has_minigame,
    enum AllScenes minigame)
{
    for (size_t i = 0; first_line[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(first_line[i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + TEXT_START_X, TEXT_START_Y, 1, 1, &tile);
    }

    for (size_t i = 0; second_line[i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(second_line[i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + TEXT_START_X, TEXT_START_Y, 1, 1, &tile);
    }

    for (size_t i = 0; names[npc][i] != '\0'; i++)
    {
        uint8_t tile = char_to_tile(names[npc][i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + NAME_START_X, NAME_START_Y, 1, 1, &tile);
    }

    uint8_t humor_icon_tile = humor_stats[npc_map] + NUMBER_TILESET_START;
    set_bkg_tiles(HUMOR_ICON_X, ICON_Y, 1, 1, &humor_icon_tile);
}