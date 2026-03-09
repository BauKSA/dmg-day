#pragma bank 3

#include <gb/gb.h>

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../map_data.h"
#include "map_23.h"

void Map_23_CheckInput() {
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A)) {
    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_DIARIOS, 0, 0, NONE);
  }
}
