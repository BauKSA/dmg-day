#pragma bank 2

#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"

#include "../../../assets/sprites/NPCs/firulais/spr_Firulais.h"

#include "map_12.h"
#include <stdint.h>

void Map_12_InitNPC()
{
  position.x[npc_1] = 81;
  position.y[npc_1] = 72;

  char npc_name[10] = "pichichus";
  for (uint8_t i = 0; npc_name[i] != '\0'; i++)
    names[npc_1][i] = npc_name[i];

  position.fixed_x[npc_1] = position.x[npc_1] << 8;
  position.fixed_y[npc_1] = position.y[npc_1] << 8;

  const unsigned char *npc_idle[] = {// primer frame
                                     spr_Firulais00, spr_Firulais01,
                                     spr_Firulais02, spr_Firulais03};

  const unsigned char *npc_run[] = {// primer frame
                                    spr_Firulais_run00, spr_Firulais_run01,
                                    spr_Firulais_run02, spr_Firulais_run03,
                                    // segundo frame
                                    spr_Firulais_run10, spr_Firulais_run11,
                                    spr_Firulais_run12, spr_Firulais_run13};

  init_animation(npc_1, &animation[npc_1], 0, npc_idle, 1,
                 DEFAULT_ANIMATION_SPEED, 4);

  init_animation(npc_1, &animation[npc_1], 1, npc_run, 2,
                 DEFAULT_ANIMATION_SPEED - 4, 4);
}
