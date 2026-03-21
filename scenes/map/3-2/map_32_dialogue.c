#pragma bank 4

#include "../../../include/npc_lines.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/mgm_states.h"
#include "./map_32.h"

static const DialoguePerRelation dialogue_0_32_es = {
    {{"ayudame con la", "tarea, dale"}, {"podrias ayudarme,", "no?"}, {"che, me das", "una mano?"}},
    {{"che, me das", "una mano?"}, {"buenas!", "tenes unminuto?"}, {"che! ayudame", "un toque, porfa"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

static const DialoguePerRelation dialogue_0_32_en = {
    {{"help me with my", "homework, go"}, {"could you help me,", "eh?"}, {"hey, give me", "a hand?"}},
    {{"hey, give me", "a hand?"}, {"hello!", "got a minute?"}, {"hey! help me", "a bit, please"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

static const DialoguePerRelation dialogue_1_32_es = {
    {{"gracias, che", ""}, {"gracias,", "me salvaste"}, {"uuh, gracias!", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"gracias! te", "debo una"}, {"gracias, genia", ""}, {"muchas gracias!", "sos lo mas"}}};

static const DialoguePerRelation dialogue_1_32_en = {
    {{"thanks, mate", ""}, {"cheers,", "saved me"}, {"uuh, thanks!", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"thanks! I", "owe you one"}, {"thanks, star", ""}, {"thanks a lot!", "you're ace"}}};

static const DialoguePerRelation dialogue_2_32_es = {
    {{"re ortiba...", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_2_32_en = {
    {{"proper mean..", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

void Map_32_InitDialogues()
{
    if (mg_32_tmp != MGM_states.mg_homework)
        dialogue_phase[(uint8_t)NPC_TAREA] = 1;

    if (dialogue_phase[(uint8_t)NPC_TAREA] == 0)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_32_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_32_en;
    }
    else if (dialogue_phase[(uint8_t)NPC_TAREA] == 1)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_32_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_32_en;
    }
    else if (dialogue_phase[(uint8_t)NPC_TAREA] == 2)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_32_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_32_en;
    }
}
