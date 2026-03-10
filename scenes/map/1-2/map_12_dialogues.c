#pragma bank 2

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "map_12.h"

const DialoguePerRelation dialogue_00_12_en = {
    {{"", ""}, {"woof, woof!", "Grrrrh..."}, {"", ""}},
    {{"", ""}, {"woof, woof!", ""}, {"", ""}},
    {{"", ""}, {"*pant, pant*", ""}, {"", ""}},
};

void Map_12_InitDialogues()
{
  // if (language == ENGLISH)
  CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_12_en;
}
