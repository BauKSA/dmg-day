#pragma bank 6

#include "./mg_mission_complete.h"
#include "../../assets/chars/chars.h"
#include "../../assets/chars/numbers.h"
#include "../../assets/sprites/backgrounds/npc_icons/npc_icons.h"
#include "../../include/char_to_tile.h"
#include "../../include/input.h"
#include "../../include/language.h"
#include "../../include/npcs.h"
#include "../../include/music.h"
#include "./mini_games.h"

#include "../../assets/sprites/backgrounds/minigames/mission_complete/bkg_mission_complete.h"

#include <gb/gb.h>
#include <stdint.h>

void Mg_SplashCompleteScreen(uint8_t npc_map, uint8_t success,
                             uint16_t reward)
{
  set_bkg_data(0, bkg_mission_complete_tileset_size,
               bkg_mission_complete_tileset);
  set_bkg_tiles(0, 0, 20, 18, bkg_mission_complete_tilemap);

  vsync();

  if (language == SPANISH)
  {
    char text[] = "mision  completa\0";
    for (uint8_t i = 0; text[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(text[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(2 + i, 3, tile);
    }

    uint8_t humor_icon = NPC_ICONS_TILESET_START + humor_stats[npc_map];
    set_bkg_tile_xy(MC_HUMOR_ICON_X, MC_HUMOR_ICON_Y, humor_icon);

    uint8_t rel_icon = NPC_ICONS_TILESET_START + relation_stats[npc_map] + 3;
    set_bkg_tile_xy(MC_REL_ICON_X, MC_REL_ICON_Y, rel_icon);

    char completa[] = "sueprada\0";
    for (uint8_t i = 0; completa[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(completa[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(1 + i, MC_TASK_COMPLETE_Y, tile);
    }

    if (success == 0)
    {
      uint8_t empty_tile = 255;
      set_bkg_tile_xy(MC_TASK_COMPLETE_X, MC_TASK_COMPLETE_Y, empty_tile);
    }

    char recompensa[] = "recompensa\0";
    for (uint8_t i = 0; recompensa[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(recompensa[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(1 + i, MC_REWARD_Y, tile);
    }

    uint8_t thousands = reward / 1000;
    uint8_t hundred = (reward % 1000) / 100;
    uint8_t tens = (reward % 100) / 10;
    uint8_t units = reward % 10;

    uint8_t index = 0;

    uint8_t tile = NUMBER_TILESET_START + thousands;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
    index++;

    tile = NUMBER_TILESET_START + hundred;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
    index++;

    tile = NUMBER_TILESET_START + tens;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
    index++;

    tile = NUMBER_TILESET_START + units;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
  }
  else
  {
    char text[] = "mission complete\0";
    for (uint8_t i = 0; text[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(text[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(2 + i, 3, tile);
    }

    uint8_t humor_icon = NPC_ICONS_TILESET_START + humor_stats[npc_map];
    set_bkg_tile_xy(MC_HUMOR_ICON_X, MC_HUMOR_ICON_Y, humor_icon);

    uint8_t rel_icon = NPC_ICONS_TILESET_START + relation_stats[npc_map] + 3;
    set_bkg_tile_xy(MC_REL_ICON_X, MC_REL_ICON_Y, rel_icon);

    char completa[] = "passed\0";
    for (uint8_t i = 0; completa[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(completa[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(1 + i, MC_TASK_COMPLETE_Y, tile);
    }

    if (success == 0)
    {
      uint8_t empty_tile = 255;
      set_bkg_tile_xy(MC_TASK_COMPLETE_X, MC_TASK_COMPLETE_Y, empty_tile);
    }

    char recompensa[] = "reward\0";
    for (uint8_t i = 0; recompensa[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(recompensa[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(1 + i, MC_REWARD_Y, tile);
    }

    uint8_t thousands = reward / 1000;
    uint8_t hundred = (reward % 1000) / 100;
    uint8_t tens = (reward % 100) / 10;
    uint8_t units = reward % 10;

    uint8_t index = 0;

    uint8_t tile = NUMBER_TILESET_START + thousands;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
    index++;

    tile = NUMBER_TILESET_START + hundred;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
    index++;

    tile = NUMBER_TILESET_START + tens;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
    index++;

    tile = NUMBER_TILESET_START + units;
    set_bkg_tile_xy(MC_REWARD_X + index, MC_REWARD_Y, tile);
  }

  if (success == 1)
  {
    MiniGamePassed();
  }
  else
  {
    MiniGameNotPassed();
  }
}

void Mg_CompleteScreenSleep()
{
  return;
}
