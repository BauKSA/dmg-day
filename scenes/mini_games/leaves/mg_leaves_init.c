#include <gb/gb.h>

#include "mg_leaves.h"
#include "../mini_games.h"
#include "../../../include/scene.h"
#include "../../../include/player.h"
#include "../../../include/position.h"

#include "../../../assets/sprites/backgrounds/template/template.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/mini_game/leaf/leaf.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/text_positions.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npc_lines.h"
#include "../../../include/load.h"
#include "../../../include/draw.h"

uint8_t leaf_ids[LEAF_COUNT];
uint8_t leaf_x[LEAF_COUNT];
int8_t leaf_y[LEAF_COUNT];
uint8_t leaf_active[LEAF_COUNT];
uint8_t leaf_timer[LEAF_COUNT];
uint16_t leaf_spawner[LEAF_COUNT];
enum LeafState leaf_state[LEAF_COUNT];
uint8_t SWEEPING_FLAG = 0;

MG_Leaves_DATA mg_leaves_DATA;

void Mg_Leaves_Init(Scene *scene, Entity scene_player)
{
    mg_leaves_DATA.bottom_limit = 120;

    scene->data = &mg_leaves_DATA;

    unsigned char _previous_bank = _current_bank;
    SWITCH_ROM_MBC1(1);

    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);

    char title[MAX_SIZE_MG_TITLE] = "sweep'em!";
    Mg_SetTitle(title);

    SWITCH_ROM_MBC1(_previous_bank);

    Mg_Leaves_Player_Init();

    uint8_t spacing = 119 / (LEAF_COUNT - 1);

    for (uint8_t i = 0; i < LEAF_COUNT; i++)
    {
        uint8_t id = load_extra_tiles(i, spr_leaf_00, 1);
        leaf_ids[i] = id;
        leaf_active[i] = false;

        leaf_x[i] = 24 + (i * spacing);

        leaf_y[i] = 0;
        leaf_state[i] = FALLING;
    }
}