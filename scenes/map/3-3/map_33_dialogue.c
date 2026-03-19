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

static const DialoguePerRelation dialogue_1_33_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"despues digame", "cuanto gasto"},
     {"gracias! despues", "digame que le debo"},
     {"le agradezco mucho", "aca lo espero"}}};

static const DialoguePerRelation dialogue_2_33_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"ya me trajo", "las cosas?"},
     {"hola, joven.", "consiguio todo?"},
     {"joven! como le", "va?"}}};

static const DialoguePerRelation dialogue_3_33_es = {
    {{"estos jovenes... no", "tienen educacion"}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

void Map_33_InitDialogues() {
  if (dialogue_phase[(uint8_t)NPC_SUPER] == 0) {
    if (language == SPANISH) {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_0_33_es;
    }
  } else if (dialogue_phase[(uint8_t)NPC_SUPER] == 1) {
    if (language == SPANISH) {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_1_33_es;
    }
  } else if (dialogue_phase[(uint8_t)NPC_SUPER] == 2) {
    if (language == SPANISH) {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_2_33_es;
    }
  } else if (dialogue_phase[(uint8_t)NPC_SUPER] == 3) {
    if (language == SPANISH) {
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_3_33_es;
    }
  }
}
