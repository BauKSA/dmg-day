pragma bank 4

#include "../../../include/npc_lines.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/mgm_states.h"
#include "./map_32.h"

static const DialoguePerRelation dialogue_0_32_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"no es hora del\0", "colegio, ya?\0"}, {"buen dia\0", ""}, {"que maravilloso\0", "dia, no?\0"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_0_32_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"it's time for", "school, y'now?"}, {"good morning", ""}, {"what a beautiful", "day, kid"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_1_32_es = {
    {{"ya que estas al", "pedo, ayudame"}, {"me ayudas a barrer", "las hojas?"}, {"me podrias dar una", "mano, por favor?"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"podrias ayudarme,", "no?"}, {"no quiero molestar", "me das una mano?"}, {"podrias ayudar a", "tu querida vecina?"}}};

static const DialoguePerRelation dialogue_1_32_en = {
    {{"help me, you're", "doing bugger all"}, {"can you help", "me out?"}, {"please, give me", "a hand with this"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"since you're free", "help me out"}, {"mind help me", "with this?"}, {"c'mon kid, be a", "hero and help me"}}};

static const DialoguePerRelation dialogue_2_32_es = {
    {{"hmpf...", "que antipatico"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_2_32_en = {
    {{"hmpf...", "how rude"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

void Map_32_InitDialogues()
{
    if (mg_32_tmp != MGM_states.homework)
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
