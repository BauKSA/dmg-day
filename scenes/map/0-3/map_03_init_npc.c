#pragma bank 1

#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"

#include "../../../assets/sprites/NPCs/vieja_anteojos/spr_ViejaAnteojos.h"

#include "map_03.h"
#include <stdint.h>

void Map_03_InitNPC()
{
    position.x[npc_1] = 64;
    position.y[npc_1] = 104;

    char npc_name[10] = "v anteojos";
    for (uint8_t i = 0; npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_ViejaAnteojos00,
        spr_ViejaAnteojos01,
        spr_ViejaAnteojos02,
        spr_ViejaAnteojos03,
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                   DEFAULT_ANIMATION_SPEED, 4);
}
