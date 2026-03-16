#pragma bank 3

#include "../../../include/npc_lines.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "./map_23.h"

const DialoguePerRelation dialogue_00_23_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"que necesitas?", ""}, {"hola", "que buscabas?"}, {"buen dia! que", "andabas buscando?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

const DialoguePerRelation dialogue_01_23_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"gracias", ""}, {"gracias por tu", "compra"}, {"gracias! disfrutalo", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

const DialoguePerRelation dialogue_00_23_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"hey", ""}, {"hello,", "what do you need?"}, {"yo, kid! what are", "you looking for?"}},
    {{"", ""}, {"", ""}, {"", ""}}};

const DialoguePerRelation dialogue_01_23_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"thanks", ""}, {"thank you!", ""}, {"cheers! enjoy it", ""}},
    {{"", ""}, {"", ""}, {"", ""}}};

void Map_23_InitDialogues()
{
  if (dialogue_phase[(uint8_t)NPC_DIARIO] == 0)
  {
    if (language == SPANISH)
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_23_es;
    else
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_23_en;
  }
  else
  {
    if (language == SPANISH)
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_23_es;
    else
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01_23_en;
  }
}
