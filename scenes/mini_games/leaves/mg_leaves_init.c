#pragma bank 2

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
#include "../../../assets/sprites/mini_game/garbage/spr_garbage.h"
#include "../../../assets/sprites/mini_game/leaf/leaf.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
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
uint8_t score = 0;
uint8_t score_cache = 0;

MG_Leaves_DATA mg_leaves_DATA;

uint8_t available_x[TOTAL_ACTORS];
uint8_t next_spawn_idx = 0;

void Mg_Leaves_Init(Scene *scene, Entity scene_player)
{
  mg_leaves_DATA.bottom_limit = 120;
  mg_leaves_DATA.right_limit = 120;
  mg_leaves_DATA.left_limit = 32;

  scene->data = &mg_leaves_DATA;

  char *txt = "move";
  char *sec_txt = "sweep";
  Instruction instruction[2];

  instruction[0].text = txt;
  instruction[0].button = DPAD;

  instruction[1].text = sec_txt;
  instruction[1].button = A;

  Mg_InstructionSet(instruction, 2);

  if (mgl_initialized == 0)
    Mg_LoadScreenInit();

  char title[MAX_SIZE_MG_TITLE] = "sweep'em!";
  Mg_SetTitle(title);

  Mg_LoadScreenUpdate();

  Mg_Leaves_LoadBKG();
  Mg_SetTitle(title);

  Mg_Leaves_Player_Init();

  for (uint8_t i = 0; i < TOTAL_ACTORS; i++)
  {
    // Distribuimos los actores en el ancho permitido (32 a 120)
    available_x[i] = 44 + (i * (80 / TOTAL_ACTORS));

    // Inicializamos los estados explícitamente
    actor_active[i] = 0;
    actor_state[i] = INACTIVE;
    actor_y[i] = 0; // Fuera de pantalla hasta que spawnee
  }

  // Init Leaves
  for (uint8_t i = 0; i <= LEAF_COUNT; i++)
  {
    uint8_t id = load_extra_tiles(i, spr_leaf_00, 1);
    actor_ids[i] = id;
    actor_active[i] = false;

    actor_x[i] = available_x[i];
    actor_spawn_x[i] = available_x[i];

    actor_y[i] = 0;
    fixed_y[i] = 0;

    actor_state[i] = INACTIVE;
  }

  // Init Garbage
  for (uint8_t i = LEAF_COUNT; i < TOTAL_ACTORS; i++)
  {
    uint8_t id = load_extra_tiles(i, spr_garbage_00, 1);
    actor_ids[i] = id;
    actor_active[i] = false;

    actor_x[i] = available_x[i];
    actor_spawn_x[i] = available_x[i];

    actor_y[i] = 0;
    fixed_y[i] = 0;

    actor_state[i] = INACTIVE;
  }

  char text[6] = "score:";

  for (uint8_t i = 0; i < 6; i++)
  {
    uint8_t char_tile = char_to_tile(text[i]) + CHARS_TILESET_START;
    set_bkg_tile_xy(TEXT_START_X + i, TEXT_START_Y, char_tile);
  }

  uint8_t thousands = ((score / 1000) % 10) + NUMBER_TILESET_START;
  uint8_t hundreds = ((score / 100) % 10) + NUMBER_TILESET_START;
  uint8_t tens = ((score / 10) % 10) + NUMBER_TILESET_START;
  uint8_t units = (score % 10) + NUMBER_TILESET_START;

  set_bkg_tile_xy(TEXT_START_X + 6 + 0, TEXT_START_Y, thousands);
  set_bkg_tile_xy(TEXT_START_X + 6 + 1, TEXT_START_Y, hundreds);
  set_bkg_tile_xy(TEXT_START_X + 6 + 2, TEXT_START_Y, tens);
  set_bkg_tile_xy(TEXT_START_X + 6 + 3, TEXT_START_Y, units);

  Mg_TimerStart(30);
}
