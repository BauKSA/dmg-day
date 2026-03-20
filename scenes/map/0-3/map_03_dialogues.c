#pragma bank 1

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "map_03.h"

const DialoguePerRelation dialogue_00_03_es = {
    {{"me podrias ayudar,", "no?"}, {"dame una mano...", ""}, {"por favor,", "no los vio?"}},
    {{"no estan en", "ningun lado..."}, {"no los encuentro", "no los encuentro"}, {"ay, no... necesito", "mis anteojos"}},
    {{"no encuentro mis", "anteojos..."}, {"no los vio por", "ahi?"}, {"por favor, joven", "necesito mis lentes"}},
};

const DialoguePerRelation dialogue_00_03_en = {
    {{"could you", "help me?"}, {"lend me a hand...", ""}, {"please, didn't you", "see them?"}},
    {{"can't find them", "anywhere..."}, {"i can't find'em", "i can't find'em"}, {"oh, no... i need", "my glasses"}},
    {{"i can't find", "my glasses..."}, {"did you not", "see'em kid?"}, {"please, kid, help", "find my glassess"}},
};

const DialoguePerRelation dialogue_01_03_es = {
    {{"", ""}, {"", ""}, {"gracias, joven", "muchas gracias"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"muchas gracias,", "tesoro!"}},
};

const DialoguePerRelation dialogue_01_03_en = {
    {{"", ""}, {"", ""}, {"thank you, kid", "you saved me"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"love yo, kid!", "you're my saviour"}},
};

void Map_03_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_ANTEOJOS] == 0)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_03_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_03_en;
    }
    else if (dialogue_phase[(uint8_t)NPC_ANTEOJOS] == 1)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_03_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_03_en;
    }
}
