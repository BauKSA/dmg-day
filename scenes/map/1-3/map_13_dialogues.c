#pragma bank 2

#include "../../../include/language.h"
#include "../../../include/npc_lines.h"
#include "../../../include/npc_stats_map.h"

#include "map_13.h"

const DialoguePerRelation dialogue_00_boca_13_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"estamos jugando", "no te metas"}, {"guarda, que", "estamos jugando"}, {"que onda??", "aguante boca, no?"}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_00_boca_13_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"hey! we are", "playing"}, {"careful, kid!", ""}, {"'aguante boca', eh?'", ""}},
    {{"", ""}, {"", ""}, {"", ""}},
};

const DialoguePerRelation dialogue_00_river_13_es = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"una vieja perdio", "los lentes, mira"}, {"mira lo que", "encontramos"}, {"che, no sabras", "de quien son?"}},
    {{"sabes de quien", "son?"}, {"toma, llevalos", ""}, {"que bueno que", "los agarramos, no?"}},
};

const DialoguePerRelation dialogue_00_river_13_en = {
    {{"", ""}, {"", ""}, {"", ""}},
    {{"an ol'hag lost", "her glassess"}, {"hey, look. we", "found them"}, {"hey, kid! you", "know the owner?"}},
    {{"you know who", "they belong to?"}, {"take it", ""}, {"ha, so good we", "saved them, eh?"}},
};

void Map_13_InitDialogues()
{
  if (language == ENGLISH)
  {
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_boca_13_en;
    CurrentNPCDialogues[1] = (DialoguePerRelation *)&dialogue_00_river_13_en;
  }
  else
  {
    CurrentNPCDialogues[0] = (DialoguePerRelation *)&dialogue_00_boca_13_es;
    CurrentNPCDialogues[1] = (DialoguePerRelation *)&dialogue_00_river_13_es;
  }
}
