#pragma bank 3

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "./map_22.h"

const DialoguePerRelation dialogue_00 = {
    {{"...", ""}, {"...", ""}, {"...", ""}},
    {{"...", ""}, {"mhmm...", ""}, {"hi...", ""}},
    {{"...", ""}, {"...", ""}, {"...", ""}}};

const DialoguePerRelation dialogue_00_en = {
    {{"", ""}, {"english text!", ""}, {"", ""}},
    {{"", ""}, {"english text b", ""}, {"", ""}},
    {{"", ""}, {"englosh text c", ""}, {"", ""}}};

const DialoguePerRelation dialogue_01 = {
    {{"...", ""}, {"...", ""}, {"...", ""}},
    {{"sec dialogue", ""}, {"sec dialogue", "xd"}, {"sec dialogue", "xddddd"}},
    {{"...", ""}, {"...", ""}, {"...", ""}}};

void Map_22_InitDialogues() {
  if (dialogue_phase[(uint8_t)NPC_MARTIN] == 0) {
    if (language == ENGLISH)
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_en;
    else
      CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00;
  } else if (dialogue_phase[(uint8_t)NPC_MARTIN] == 1)
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_01;
}
