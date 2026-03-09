#pragma bank 3

#include "./map_22.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

const DialoguePerRelation dialogue_00 = {
    {{"...", ""}, {"...", ""}, {"...", ""}},
    {{"...", ""}, {"mhmm...", ""}, {"hi...", ""}},
    {{"...", ""}, {"...", ""}, {"...", ""}}};

    const DialoguePerRelation dialogue_00 = {
    {{"...", ""}, {"...", ""}, {"...", ""}},
    {{"sec dialogue", ""}, {"sec dialogue", "xd"}, {"sec dialogue", "xddddd"}},
    {{"...", ""}, {"...", ""}, {"...", ""}}};

void Map_22_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_MARTIN] == 0){
        CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00;
    }
    else if (dialogue_phase[(uint8_t)NPC_MARTIN] == 1)
        CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01;
}