#pragma bank 2

#include <gb/gb.h>

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/music.h"
#include "../../../include/npcs.h"
#include "../map_data.h"

void Map_12_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A))
  {
    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_FIRULAIS, 0, 0, NONE);
    Woof();
  }
}
