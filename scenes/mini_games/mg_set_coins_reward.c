#include "mg_set_coins_reward.h"
#include "../../include/money.h"
#include "../../include/npcs.h"
#include <stdint.h>

uint16_t Mg_SetCoinsReward(uint8_t npc_map, uint8_t success) {
  uint16_t tmp = money;
  uint8_t good_relation = 0;
  uint8_t humor = humor_stats[npc_map];

  if (relation_stats[npc_map] == 2)
    good_relation = 1;

  if (humor == 0) {
    if (success == 0 && good_relation == 0)
      money += 500;
    else if (success == 1 && good_relation == 0)
      money += 2100;
    else if (success == 0 && good_relation == 1)
      money += 800;
    else if (success == 1 && good_relation == 1)
      money += 3500;
  } else if (humor == 1) {
    if (success == 0 && good_relation == 0)
      money += 600;
    else if (success == 1 && good_relation == 0)
      money += 2300;
    else if (success == 0 && good_relation == 1)
      money += 900;
    else if (success == 1 && good_relation == 1)
      money += 3800;
  } else if (humor == 2) {
    if (success == 0 && good_relation == 0)
      money += 700;
    else if (success == 1 && good_relation == 0)
      money += 2500;
    else if (success == 0 && good_relation == 1)
      money += 1000;
    else if (success == 1 && good_relation == 1)
      money += 4200;
  }
}
