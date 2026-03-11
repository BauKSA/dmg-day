#pragma bank 4

#include "../../../include/npc_lines.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "./map_30.h"

const DialoguePerRelation dialogue_0_30_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"no es hora del", "colegio, ya?"}, {"buen dia", ""}, {"que maravilloso", "dia, no?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

const DialoguePerRelation dialogue_0_30_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"it's time for", "school, y'now?"}, {"good morning", ""}, {"what a beautiful", "day, kid"}},
    {{"", ""}, {"", ""}, {"", ""}}};

const DialoguePerRelation dialogue_1_30_es = {
    {{"ya que estas al", "pedo, ayudame"}, {"me ayudas a barrer", "las hojas?"}, {"me podrias dar una", "mano, por favor?"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"podrias ayudarme,", "no?"}, {"no quiero molestar", "me das una mano?"}, {"podrias ayudar a", "tu querida vecina?"}}};

const DialoguePerRelation dialogue_1_30_en = {
    {{"help me, you're", "doing bugger all"}, {"can you help", "me out?"}, {"please, give me", "a hand with this"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"since you're free", "help me out"}, {"mind help me", "with this?"}, {"c'mon kid, be a", "hero and help me"}}};

const DialoguePerRelation dialogue_2_30_es = {
    {{"para eso lo hacia", "yo..."}, {"gracias...", ""}, {"gracias. no faltes", "al colegio!"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"gracias. hiciste", "mas que mis nietos"}, {"gracias! saludos", "a tu madre"}, {"me salvaste,", "corazon. gracias!"}}};

const DialoguePerRelation dialogue_2_30_en = {
    {{"should've just", "done it myself..."}, {"thanks...", ""}, {"thank you. go", "to school, c'mon"}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"thank you. i appreciate it"}, {"thank you!", "greet your mother"}, {"saved me,", "sweetheart. thank you!"}}};

void Map_23_InitDialogues()
{
    if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 1)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_30_en;
    }
    else if (dialogue_phase[(uint8_t)NPC_ESCOBA] == 2)
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_30_en;
    }
    else
    {
        if (language == SPANISH)
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_30_es;
        else
            CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_30_en;
    }
}
