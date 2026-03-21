#pragma bank 6

#include <gb/gb.h>

#include "../mg_load_screen.h"
#include "../mg_timer.h"
#include "../mini_games.h"
#include "../mg_instruction_set.h"
#include "mg_final.h"

#include "../../../include/player.h"
#include "../../../include/position.h"
#include "../../../include/scene.h"

#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/backgrounds/minigames/final/bkg_final.h"

#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
#include "../../../include/language.h"
#include "../../../include/load.h"
#include "../../../include/name.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/text_positions.h"
#include "../../../include/mgm_states.h"

void Mg_Final_Init(Scene *scene, Entity scene_player)
{
    if (language == ENGLISH)
    {
        char *txt = "move";
        char *txt_b = "action";

        Instruction instruction[2];

        instruction[0].text = txt;
        instruction[0].button = DPAD;

        instruction[1].text = txt_b;
        instruction[1].button = B;

        char *req_a = "wins";

        Requirement reqs[1];

        reqs[0].text = req_a;
        reqs[0].qty = 4;

        Mg_InstructionSet(instruction, 2, reqs, 1);

        if (mgl_active == 0)
            Mg_LoadScreenInit();

        char title[MAX_SIZE_MG_TITLE] = "play!";
        Mg_SetTitle(title);

        Mg_LoadScreenUpdate();

        set_bkg_data(0, bkg_final_tileset_size, bkg_final_tileset);
        set_bkg_tiles(0, 0, 20, 18, bkg_final_tilemap);

        Mg_SetTitle(title);
    }
    else
    {
        char *txt = "moverse";
        char *txt_b = "accion";

        Instruction instruction[2];

        instruction[0].text = txt;
        instruction[0].button = DPAD;

        instruction[1].text = txt_b;
        instruction[1].button = B;

        char *req_a = "superados";

        Requirement reqs[1];

        reqs[0].text = req_a;
        reqs[0].qty = 4;

        Mg_InstructionSet(instruction, 2, reqs, 1);

        if (mgl_initialized == 0)
            Mg_LoadScreenInit();

        char title[MAX_SIZE_MG_TITLE] = "juga!";
        Mg_SetTitle(title);

        Mg_LoadScreenUpdate();

        set_bkg_data(0, bkg_final_tileset_size, bkg_final_tileset);
        set_bkg_tiles(0, 0, 20, 18, bkg_final_tilemap);

        Mg_SetTitle(title);
    }

    MGM_states.mg_final = MGM_INACTIVE;
}