#pragma bank 2

#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"

#include "../../../assets/sprites/NPCs/boca/spr_boquita.h"
#include "../../../assets/sprites/NPCs/river/spr_gallina.h"

#include "map_13.h"
#include <stdint.h>

void Map_13_InitNPCs()
{
    // BOCA
    position.x[npc_1] = 120;
    position.y[npc_1] = 64;

    char npc_name[10] = "roman";
    for (uint8_t i = 0; npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    const unsigned char *npc_idle[] = {// primer frame
                                       spr_boquita00, spr_boquita01,
                                       spr_boquita02, spr_boquita03};

    init_animation(npc_1, &animation[npc_1], 0, npc_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 4);

    // GALLINA
    position.x[npc_2] = 128;
    position.y[npc_2] = 96;

    char npc_name_2[10] = "enzo";
    for (uint8_t i = 0; npc_name_2[i] != '\0'; i++)
        names[npc_2][i] = npc_name_2[i];

    position.fixed_x[npc_2] = position.x[npc_2] << 8;
    position.fixed_y[npc_2] = position.y[npc_2] << 8;

    const unsigned char *npc_idle_2[] = {// primer frame
                                         spr_gallina00, spr_gallina01,
                                         spr_gallina02, spr_gallina03};

    init_animation(npc_2, &animation[npc_2], 0, npc_idle_2, 1,
                   DEFAULT_ANIMATION_SPEED, 4);
}
