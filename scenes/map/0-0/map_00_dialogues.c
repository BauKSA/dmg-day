#pragma bank 1

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "map_00.h"

const DialoguePerRelation dialogue_00_00_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"queres la nueva", "game boy, eh?"}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_00_00_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"do you want the", "new game boy, eh?"}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_01_00_es = {
    {{"", ""}, {"nah, no estas", "para esto..."}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"ja! la tenes", "clara, eh?"}},
};

const DialoguePerRelation dialogue_01_00_en = {
    {{"", ""}, {"nah, kid...", "go to school"}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"ha! you know your", "onions, eh?"}},
};

void Map_00_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_TIENDA] == 0)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_00_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_00_en;
    }
    else if (dialogue_phase[(uint8_t)NPC_TIENDA] == 1)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_00_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_00_en;
    }
}
