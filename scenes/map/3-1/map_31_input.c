#pragma bank 4

#include <gb/gb.h>

#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
#include "../../../include/input.h"
#include "../../../include/inventory.h"
#include "../../../include/language.h"
#include "../../../include/mgm_states.h"
#include "../../../include/money.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/music.h"

#include "../../../assets/chars/buttons.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../../../assets/sprites/frames/text_frame.h"

#include "../2-0/map_20.h"
#include "../map_data.h"

#include "map_31.h"

void Map_31_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  if (active_item == 0)
    return;

  if (inventory[active_item_index].item != BOOK)
    return;

  // TODO Esto hay que mandarlo a una función distinta Map_31_CheckItems
  active_item = 0;

  if (purchased_book == WAR)
  {
    relation_stats[(uint8_t)NPC_LIBRO] = 2;
    humor_stats[(uint8_t)NPC_LIBRO] = 2;

    Scene_DrawNPCLine(npc_2, (uint8_t)NPC_LIBRO, 1, 0, NONE);

    book_delivered = 1;

    for (uint8_t i = 0; i < MAX_ITEMS; i++)
    {
      if (inventory[i].item == BOOK)
      {
        inventory[i].item = ITM_NONE;
        MGM_states.book = 0;

        break;
      }
    }

    MiniGamePassed();

    money += 1500;

    TextFrame_Init(12, 2);
    char *new_money;

    if (language == SPANISH)
      new_money = "recibiste";
    else
      new_money = "you received";

    for (uint8_t i = 0; new_money[i] != '\0'; i++)
    {
      uint8_t tile = char_to_tile(new_money[i]) + CHARS_TILESET_START;
      set_bkg_tile_xy(3 + i, 4, tile);
    }

    uint8_t digits[5];
    uint16_t tmp_reward = 1500;

    for (uint8_t i = 5; i >= 1; i--)
    {
      digits[i - 1] = tmp_reward % 10;
      tmp_reward /= 10;
    }

    uint8_t tile_symbol = char_to_tile('$') + CHARS_TILESET_START;
    set_bkg_tile_xy(3, 5, tile_symbol);

    for (uint8_t i = 0; i < 5; i++)
    {
      uint8_t tile = digits[i] + NUMBER_TILESET_START;
      set_bkg_tile_xy(4 + i, 5, tile);
    }

    for (uint8_t i = 0; i < 180; i++)
      vsync();

    TextFrame_Close(12, 2);
    EarnMoney();
  }
  else
  {
    relation_stats[(uint8_t)NPC_LIBRO] = 0;
    humor_stats[(uint8_t)NPC_LIBRO] = 0;

    Scene_DrawNPCLine(npc_2, (uint8_t)NPC_LIBRO, 0, 0, NONE);
  }
}
