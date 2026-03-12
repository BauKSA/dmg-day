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
#include "../../../assets/sprites/objects/acorn/spr_acorn.h"
#include "../../../assets/sprites/objects/leaf/spr_leaf_a.h"
#include "../../../assets/sprites/objects/leaf/spr_leaf_b.h"

#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
#include "../../../include/language.h"
#include "../../../include/load.h"
#include "../../../include/name.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/text_positions.h"

uint8_t actor_ids[TOTAL_ACTORS];
uint8_t actor_x[TOTAL_ACTORS];
uint8_t actor_y[TOTAL_ACTORS];
uint16_t fixed_y[TOTAL_ACTORS];
uint8_t actor_active[TOTAL_ACTORS];
uint8_t actor_timer[TOTAL_ACTORS];
uint16_t actor_spawner[TOTAL_ACTORS];
uint8_t actor_spawn_x[TOTAL_ACTORS];
enum ActorState actor_state[TOTAL_ACTORS];
uint8_t SWEEPING_FLAG = 0;

MG_Leaves_DATA mg_leaves_DATA;

uint8_t available_x[TOTAL_ACTORS];
uint8_t next_spawn_idx = 0;

// SCORE
uint8_t min_acorns = 5;
uint8_t min_leaves = 10;
uint8_t acorns_count = 0;
uint8_t leaves_count = 0;

void Mg_Leaves_Init(Scene *scene, Entity scene_player)
{
  mg_leaves_DATA.bottom_limit = 120;
  mg_leaves_DATA.right_limit = 120;
  mg_leaves_DATA.left_limit = 32;

  scene->data = &mg_leaves_DATA;

  if (language == ENGLISH)
  {
    char *txt = "move";
    char *sec_txt = "sweep";

    Instruction instruction[2];

    instruction[0].text = txt;
    instruction[0].button = DPAD;

    instruction[1].text = sec_txt;
    instruction[1].button = A;

    char *req_a = "leaves";
    char *req_b = "acorns";

    Requirement reqs[2];

    reqs[0].text = req_a;
    reqs[0].qty = 8;

    reqs[1].text = req_b;
    reqs[1].qty = 5;

    Mg_InstructionSet(instruction, 2, reqs, 2);

    if (mgl_initialized == 0)
      Mg_LoadScreenInit();

    char title[MAX_SIZE_MG_TITLE] = "sweep'em!";
    Mg_SetTitle(title);

    Mg_LoadScreenUpdate();

    Mg_Leaves_LoadBKG();
    Mg_SetTitle(title);
  }
  else
  {
    char *txt = "mover";
    char *sec_txt = "barrer";
    Instruction instruction[2];

    instruction[0].text = txt;
    instruction[0].button = DPAD;

    instruction[1].text = sec_txt;
    instruction[1].button = A;

    char *req_a = "hojas\0";
    char *req_b = "bellotas\0";

    Requirement reqs[2];

    reqs[0].text = req_a;
    reqs[0].qty = 8;

    reqs[1].text = req_b;
    reqs[1].qty = 5;

    Mg_InstructionSet(instruction, 2, reqs, 2);

    if (mgl_initialized == 0)
      Mg_LoadScreenInit();

    char title[MAX_SIZE_MG_TITLE] = "barre!";
    Mg_SetTitle(title);

    Mg_LoadScreenUpdate();

    Mg_Leaves_LoadBKG();
    Mg_SetTitle(title);
  }

  Mg_Leaves_Player_Init();

  for (uint8_t i = 0; i < TOTAL_ACTORS; i++)
  {
    available_x[i] = 44 + (i * (80 / TOTAL_ACTORS));

    actor_active[i] = 0;
    actor_state[i] = INACTIVE;
    actor_y[i] = 0;
  }

  for (uint8_t i = 0; i <= LEAF_COUNT; i++)
  {
    uint8_t id;

    if (i % 2 == 0)
      id = load_extra_tiles(i, spr_leaf_a, 1);
    else
      id = load_extra_tiles(i, spr_leaf_b, 1);

    actor_ids[i] = id;
    actor_active[i] = false;

    actor_x[i] = available_x[i];
    actor_spawn_x[i] = available_x[i];

    actor_y[i] = 0;
    fixed_y[i] = 0;

    actor_state[i] = INACTIVE;
  }

  for (uint8_t i = LEAF_COUNT; i < TOTAL_ACTORS; i++)
  {
    uint8_t id = load_extra_tiles(i, spr_acorn, 1);
    actor_ids[i] = id;
    actor_active[i] = false;

    actor_x[i] = available_x[i];
    actor_spawn_x[i] = available_x[i];

    actor_y[i] = 0;
    fixed_y[i] = 0;

    actor_state[i] = INACTIVE;
  }

  Mg_TimerStart(30);
}
