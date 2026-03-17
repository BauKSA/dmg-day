#pragma bank 1

#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"

#include "../../../assets/sprites/NPCs/pigeon/spr_Pigeon.h"

#include "map_02.h"
#include <stdint.h>

void Map_02_InitNPC()
{
    position.x[npc_1] = 72;
    position.y[npc_1] = 72;

    char npc_name[10] = "paloma";
    for (uint8_t i = 0; npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    const unsigned char *npc_idle[] = {// primer frame
                                       spr_Pigeon0};

    const unsigned char *npc_picotazo[] = {// primer frame
                                           spr_Pigeon0,
                                           // segundo frame
                                           spr_Pigeon1};

    init_animation(npc_1, &animation[npc_1], 0, npc_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 1);

    init_animation(npc_1, &animation[npc_1], 1, npc_picotazo, 2,
                   DEFAULT_ANIMATION_SPEED, 1);
}
