#pragma bank 4

#include <gb/gb.h>

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../map_data.h"
#include "map_32.h"

void Map_32_CheckInput() {
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A)) {
    uint8_t mg_active = 0;
    enum AllScenes mg = NONE;

    if (dialogue_phase[(uint8_t)NPC_TAREA] == 0) {
      mg = MG_HOMEWORK;
      mg_active = 1;
    }

    if (dialogue_phase[(uint8_t)NPC_TAREA] == 0)
      tmp_relation32 = 2;

    uint8_t tmp = dialogue_phase[(uint8_t)NPC_TAREA];

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_TAREA, 0, mg_active, mg);

    if (dialogue_phase[(uint8_t)NPC_TAREA] != tmp) {
      Map_32_InitDialogues();
      clean();
      mg_32_tmp = MGM_states.mg_homework;
      Scene_DrawNPCLine(npc_1, (uint8_t)NPC_TAREA, 0, 0, NONE);
    }
  }
}
