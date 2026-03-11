#pragma bank 2

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "map_12.h"

const DialoguePerRelation dialogue_00_12_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"woof, woof!", "grrrrh..."}, {"woof, woof!", ""}, {"*pant, pant*", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_00_12_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"guau, guau!", "grrrrh..."}, {"guau, guau!", ""}, {"*jadeo, jadeo*", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

void Map_12_InitDialogues()
{
  if (language == ENGLISH)
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_12_en;
  else
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_12_es;
}
