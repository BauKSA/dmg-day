#pragma bank 4

#include <gb/gb.h>

#include "../../../include/input.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../map_data.h"
#include "map_30.h"

void Map_30_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  if (!(keys & J_A) && (prev_keys & J_A))
  {
    uint8_t mg_active = 0;
    enum AllScenes mg = NONE;

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 1)
    {
      mg_active = 1;
      mg = MG_LEAVES;
    }

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 0)
    {
      tmp_relation = 2;
    }

    uint8_t tmp = dialogue_phase[(uint8_t)NPC_ESCOBA];

    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, mg_active, mg);

    if (dialogue_phase[(uint8_t)NPC_ESCOBA] != tmp)
    {
      Map_30_InitDialogues();
      clean();
      mg_ended = 0;
      Scene_DrawNPCLine(npc_1, (uint8_t)NPC_ESCOBA, 0, 0, NONE);
    }
  }
}