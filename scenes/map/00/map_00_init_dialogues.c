#include "./map_00.h"
#include "../../../include/npc_lines.h"

const DialoguePerRelation dialogue_00 = {
    {{"...", ""}, {"...", ""}, {"...", ""}},
    {{"mmmh...", ""}, {"hi!", ""}, {"hello, world!", ""}},
    {{"...", ""}, {"...", ""}, {"...", ""}}};

void Map_00_InitDialogues()
{
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00;
}