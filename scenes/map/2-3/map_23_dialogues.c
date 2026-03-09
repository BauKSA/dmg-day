#pragma bank 3

#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"
#include "./map_23.h"

const DialoguePerRelation dialogue_00_23 = {
    {{"", ""}, {"hola", "boludazo"}, {"", ""}},
    {{"", ""}, {"hola", ""}, {"", ""}},
    {{"", ""}, {"que haces,", "maquinola"}, {"", ""}}};

void Map_23_InitDialogues() {
  CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_23;
}
