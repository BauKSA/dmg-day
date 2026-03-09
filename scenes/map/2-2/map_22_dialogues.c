#pragma bank 3

#include "./map_22.h"
#include "../../../include/npc_lines.h"

const DialoguePerRelation dialogue_00 = {
    {{"...", ""}, {"...", ""}, {"...", ""}},
    {{"...", ""}, {"mhmm...", ""}, {"hi...", ""}},
    {{"...", ""}, {"...", ""}, {"...", ""}}};

void Map_22_InitDialogues()
{
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00;
}