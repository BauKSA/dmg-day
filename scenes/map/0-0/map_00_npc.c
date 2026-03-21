#pragma bank 1

#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"

#include "../../../assets/sprites/NPCs/tienda/spr_tienda.h"

#include "map_00.h"
#include <stdint.h>

void Map_00_InitNPC()
{
    position.x[npc_1] = 64;
    position.y[npc_1] = 88;

    char npc_name[10] = "gerardo";
    for (uint8_t i = 0; npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    const unsigned char *npc_idle[] = {
        // primer frame
        spr_tienda00,
        spr_tienda01,
        spr_tienda02,
        spr_tienda03,
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_idle, 1,
                   DEFAULT_ANIMATION_SPEED, 4);
}
