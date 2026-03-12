#pragma bank 6

#include <gb/gb.h>

#include "../mg_load_screen.h"
#include "../mg_timer.h"
#include "../mini_games.h"
#include "../mg_instruction_set.h"
#include "mg_leaves.h"

#include "../../../include/player.h"
#include "../../../include/position.h"
#include "../../../include/scene.h"

#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/backgrounds/template/template.h"

#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
#include "../../../include/language.h"
#include "../../../include/load.h"
#include "../../../include/name.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/text_positions.h"



void Mg_Leaves_Init(Scene *scene, Entity scene_player)
{
  if (language == ENGLISH)
  {
    char *txt = "select opt.";

    Instruction instruction[1];

    instruction[0].text = txt;
    instruction[0].button = DPAD;

    char *req_a = "correct opt.";

    Requirement reqs[1];

    reqs[0].text = req_a;
    reqs[0].qty = 4;

    Mg_InstructionSet(instruction, 1, reqs, 1);

    if(mgl_active == 0)
        Mg_LoadScreenInit();

    char title[MAX_SIZE_MG_TITLE] = "answer all!";
    Mg_SetTitle(title);

    Mg_LoadScreenUpdate();

    Mg_Leaves_LoadBKG();
    Mg_SetTitle(title);
  }
  else
  {
    char *txt = "responder";
    Instruction instruction[1];

    instruction[0].text = txt;
    instruction[0].button = DPAD;

    char *req_a = "resp. correctas";

    Requirement reqs[1];

    reqs[0].text = req_a;
    reqs[0].qty = 4;

    Mg_InstructionSet(instruction, 1, reqs, 1);

    if (mgl_initialized == 0)
      Mg_LoadScreenInit();

    char title[MAX_SIZE_MG_TITLE] = "responde!";
    Mg_SetTitle(title);

    Mg_LoadScreenUpdate();

    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);

    Mg_SetTitle(title);
  }
}
