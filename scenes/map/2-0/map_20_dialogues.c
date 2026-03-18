#pragma bank 1

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "map_20.h"

const DialoguePerRelation dialogue_00_20_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"no, no, no", "no, no, no..."}, {"not even if i run", "i won't make it!"}, {"ay, i don't want", "to be lateee"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_00_20_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"no, no, no", "no, no, no..."}, {"ni aunque corra...", "no llego!"}, {"ay, no quiero", "llegar tardeee"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_01_20_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"te doy la plata,", "comprame el libro"}, {"no llego... me", "lo compras, porfa?"}, {"holi! necesito un", "favorcito..."}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_01_20_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"take the money and", "buy me the book"}, {"please!", "buy it for me"}, {"hi! would you ", "mind...?"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_02_20_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"te espero en", "el colegio"}, {"gracias! te veo", "en el colegio"}, {"ay, gracias! nos", "vemos en el cole"}},
};

const DialoguePerRelation dialogue_02_20_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"i will wait at", "the school"}, {"thanks! see", "you in school"}, {"thank you!", "meet at school!"}},
};

const DialoguePerRelation dialogue_03_20_es = {
    {{"bueno...", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_03_20_en = {
    {{"okey...", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

void Map_20_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_LIBRO] == 0)
    {
        if (language == ENGLISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_20_en;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_20_es;
    }
    else if (dialogue_phase[(uint8_t)NPC_LIBRO] == 1)
    {
        if (language == ENGLISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_20_en;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_20_es;
    }
    else if (dialogue_phase[(uint8_t)NPC_LIBRO] == 2)
    {
        if (language == ENGLISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_02_20_en;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_02_20_es;
    }

    else if (dialogue_phase[(uint8_t)NPC_LIBRO] == 3)
    {
        if (language == ENGLISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_03_20_en;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_03_20_es;
    }
}