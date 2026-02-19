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

void Mg_Leaves_Init(Scene *scene, Entity scene_player)
{
    scene->data = NULL;

    unsigned char _previous_bank = _current_bank;
    SWITCH_ROM_MBC1(1);

    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);

    char title[MAX_SIZE_MG_TITLE] = "sweep'em!";
    Mg_SetTitle(title);

    SWITCH_ROM_MBC1(_previous_bank);

    Mg_Leaves_Player_Init();

    /**
     * [DEBUG:]
     * Inicializamos hoja de ejemplo, a ver cómo funcionan
     * los extra actor
     */

     uint8_t leaf_id = load_extra_tiles(1, spr_leaf_00, 1);
     draw_extra(leaf_id, 50, 50, 1, 1);
}