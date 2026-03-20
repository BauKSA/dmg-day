#include <stdint.h>
#pragma bank 5

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "./map_33.h"

static const DialoguePerRelation dialogue_0_33_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmmhm... me duele", "todo. me ayudas?"},
     {"podria ayudarme", "por favor?"},
     {"disculpe, joven!", "me hace un favor?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_0_33_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"mmmhm... my knees", "will you help me?"},
     {"please, do me", "a favour"},
     {"excuse me, kid!", "ask for a favour?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_1_33_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"despues digame", "cuanto gasto"},
     {"gracias! despues", "digame que le debo"},
     {"le agradezco mucho", "aca lo espero"}}};

static const DialoguePerRelation dialogue_1_33_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"tell me what", "you spent"},
     {"thanks! then let", "me know the cost"},
     {"much appreciated!", "will wait you here"}}};

static const DialoguePerRelation dialogue_2_33_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"ya me trajo", "las cosas?"},
     {"hola, joven.", "consiguio todo?"},
     {"joven! como le", "va?"}}};

static const DialoguePerRelation dialogue_2_33_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"got the stuff?", ""},
     {"hi, kid! did you", "get everything?"},
     {"kid! are you", "doing well?"}}};

static const DialoguePerRelation dialogue_3_33_es = {
    {{"estos jovenes no", "tienen respeto"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_3_33_en = {
    {{"this kids today...", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

static const DialoguePerRelation dialogue_4_33_es = {
    {{"nada... no me", "trajo nada..."}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"bueno, algo es", "algo..."}, {"", ""}, {"muchas gracias,", "joven. disfrute"}}};

static const DialoguePerRelation dialogue_4_33_en = {
    {{"nothing", "you get me nothing"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"well... it's no", "so bad"}, {"", ""}, {"many thanks, kid!", "take it, enjoy it"}}};

void Map_33_InitDialogues()
{
  if (dialogue_phase[(uint8_t)NPC_SUPER] == 0)
  {
    if (language == SPANISH)
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_33_es;
    }
    else
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_33_en;
    }
  }
  else if (dialogue_phase[(uint8_t)NPC_SUPER] == 1)
  {
    if (language == SPANISH)
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_33_es;
    }
    else
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_33_en;
    }
  }
  else if (dialogue_phase[(uint8_t)NPC_SUPER] == 2)
  {
    if (language == SPANISH)
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_33_es;
    }
    else
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_33_en;
    }
  }
  else if (dialogue_phase[(uint8_t)NPC_SUPER] == 3)
  {
    if (language == SPANISH)
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_3_33_es;
    }
    else
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_3_33_en;
    }
  }
  else if (dialogue_phase[(uint8_t)NPC_SUPER] == 4)
  {
    if (language == SPANISH)
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_4_33_es;
    }
    else
    {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_4_33_en;
    }
  }
}
