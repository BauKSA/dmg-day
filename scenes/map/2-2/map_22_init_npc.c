#pragma bank 3

#include "./map_22.h"
#include "../map_data.h"
#include "../../../assets/sprites/NPCs/martin/martin_npc.h"
#include "../../../include/animation.h"
#include "../../../include/entity.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../../../include/load.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"

void Map_22_InitNPC()
{
    position.x[npc_1] = 38;
    position.y[npc_1] = 75;

    char npc_name[10] = "martin";
    for (size_t i = 0; npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 4;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_patrol[] = {
        // primer frame
        spr_Martin_down00,
        spr_Martin_down01,
        spr_Martin_down02,
        spr_Martin_down03,

        // segundo frame
        spr_Martin_down10,
        spr_Martin_down11,
        spr_Martin_down12,
        spr_Martin_down13,
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_patrol, 2, DEFAULT_ANIMATION_SPEED * 3, 4);
}