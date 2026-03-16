#pragma bank 3

#include "./map_20.h"

#include "../../../assets/sprites/NPCs/chica_libro/spr_ChicaLibro.h"
#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../map_data.h"

void Map_20_InitNPC()
{
    position.x[npc_1] = 64;
    position.y[npc_1] = 56;

    char npc_name[10] = "c. libro";
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
        spr_ChicaLibro00,
        spr_ChicaLibro01,
        spr_ChicaLibro02,
        spr_ChicaLibro03
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 1,
                   DEFAULT_ANIMATION_SPEED, 4);
}
