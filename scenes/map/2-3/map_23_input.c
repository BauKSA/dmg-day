#pragma bank 3

#include <gb/gb.h>

#include "../../../include/input.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/language.h"
#include "../../../assets/sprites/frames/text_frame.h"
#include "../../../assets/chars/chars.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../map_data.h"
#include "map_23.h"

void Map_23_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A))
  {
    if (dialogue_phase[(uint8_t)NPC_DIARIO] == 0)
    {
      Scene_DrawNPCLine(npc_1, (uint8_t)NPC_DIARIO, 0, 0, NONE);
      Map_23_ShowBooks();

      keys = 0;
      prev_keys = 0;
    }
  }
}
