#pragma bank 4

#include "../../../include/npc_lines.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/mgm_states.h"
#include "./map_32.h"

static const DialoguePerRelation dialogue_0_32_es = {
    {{"dialogo a.c", "humor c"}, {"dialogo a.c", "humor b"}, {"dialogo a.c", "humor a"}},
    {{"dialogo a.b", "humor c"}, {"dialogo a.b", "humor b"}, {"dialogo a.b", "humor a"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

static const DialoguePerRelation dialogue_0_32_en = {
    {{"dialogue a.c", "mood c"}, {"dialogue a.c", "mood b"}, {"dialogue a.c", "mood a"}},
    {{"dialogue a.b", "mood c"}, {"dialogue a.b", "mood b"}, {"dialogue a.b", "mood a"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_1_32_es = {
    {{"gracias.c", "humor c"}, {"gracias.c", "humor b"}, {"gracias.c", "humor a"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"gracias.a", "humor c"}, {"gracias.a", "humor b"}, {"gracias.a", "humor a"}}};

static const DialoguePerRelation dialogue_1_32_en = {
    {{"thanks.c", "mood c"}, {"thanks.c", "mood b"}, {"thanks.c", "mood a"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"thanks.a", "mood c"}, {"thanks.a", "mood b"}, {"thanks.a", "mood a"}}};

static const DialoguePerRelation dialogue_2_32_es = {
    {{"puto", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_2_32_en = {
    {{"puto", "in english"}, {"", ""}, {"", ""}},
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
