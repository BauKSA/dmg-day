#pragma bank 2

#include <gb/gb.h>

#include "mg_leaves.h"
#include "../mini_games.h"
#include "../../../include/scene.h"
#include "../../../include/player.h"
#include "../../../include/position.h"

#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/mini_game/leaf/leaf.h"
#include "../../../assets/sprites/mini_game/garbage/spr_garbage.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/text_positions.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npc_lines.h"
#include "../../../include/load.h"
#include "../../../include/draw.h"

uint8_t actor_ids[TOTAL_ACTORS];
uint8_t actor_x[TOTAL_ACTORS];
int8_t actor_y[TOTAL_ACTORS];
uint8_t actor_active[TOTAL_ACTORS];
uint8_t actor_timer[TOTAL_ACTORS];
uint16_t actor_spawner[TOTAL_ACTORS];
uint8_t actor_spawn_x[TOTAL_ACTORS];
enum ActorState actor_state[TOTAL_ACTORS];
uint8_t SWEEPING_FLAG = 0;
uint8_t score = 0;
uint8_t score_cache = 0;

MG_Leaves_DATA mg_leaves_DATA;

void Mg_Leaves_Init(Scene *scene, Entity scene_player)
{
    mg_leaves_DATA.bottom_limit = 120;
    mg_leaves_DATA.right_limit = 120;
    mg_leaves_DATA.left_limit = 32;

    scene->data = &mg_leaves_DATA;

    Mg_Leaves_LoadBKG();

    char title[MAX_SIZE_MG_TITLE] = "sweep'em!";
    Mg_SetTitle(title);

    Mg_Leaves_Player_Init();

    // Init Leaves
    uint8_t leaf_spacing = 80 / (LEAF_COUNT - 1);

    for (uint8_t i = 0; i < LEAF_COUNT; i++)
    {
        uint8_t id = load_extra_tiles(i, spr_leaf_00, 1);
        actor_ids[i] = id;
        actor_active[i] = false;

        actor_x[i] = 40 + (i * leaf_spacing);
        actor_spawn_x[i] = 40 + (i * leaf_spacing);

        actor_y[i] = 0;
        actor_state[i] = FALLING;
    }

    // Init Garbage
    uint8_t garbage_spacing = 80 / (GARBAGE_COUNT - 1);
    for (uint8_t i = LEAF_COUNT; i < TOTAL_ACTORS; i++)
    {
        uint8_t id = load_extra_tiles(i, spr_garbage_00, 1);
        actor_ids[i] = id;
        actor_active[i] = false;
        actor_x[i] = 40 + (i - LEAF_COUNT) * garbage_spacing;
        actor_spawn_x[i] = 40 + (i - LEAF_COUNT) * garbage_spacing;
        actor_y[i] = 0;
        actor_state[i] = FALLING;

        for (uint8_t j = 0; j < LEAF_COUNT; j++)
        {
            if (actor_x[i] == actor_x[j])
            {
                actor_x[i] += 10;
                actor_spawn_x[i] += 10;
                break;
            }
        }
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
}