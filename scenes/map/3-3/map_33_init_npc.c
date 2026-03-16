#pragma bank 5

#include "./map_33.h"

#include "../../../assets/sprites/NPCs/viejo_super/spr_ViejoSuper.h"
#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../map_data.h"

void Map_33_InitNPC()
{
    position.x[npc_1] = 96;
    position.y[npc_1] = 96;

    char npc_name[10] = "v. super";
    uint8_t i = 0;
    for (i = 0; i < npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    names[npc_1][i] = '\0';

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_x[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 4;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] = {
        // primer frame
        spr_ViejoSuper00,
        spr_ViejoSuper01,
        spr_ViejoSuper02,
        spr_ViejoSuper03,
        // segundo frame
        spr_ViejoSuper10,
        spr_ViejoSuper11,
        spr_ViejoSuper12,
        spr_ViejoSuper13,
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 2,
                   DEFAULT_ANIMATION_SPEED * 3, 4);
}
