#include "./map_00.h"
#include "../map_data.h"
#include "../../../assets/sprites/NPCs/example/example_npc.h"
#include "../../../include/animation.h"
#include "../../../include/entity.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../../../include/load.h"

void Map_00_NPC_Init(Scene *scene){
    position.x[npc_1] = 40;
    position.y[npc_1] = 80;

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 4;
    render.vertical[npc_1] = TRUE;

    // PLAYER DOWN ANIMATIONS
    const unsigned char *npc_idle[] = {
        spr_adolfito_00,
        spr_adolfito_10,
        spr_adolfito_01,
        spr_adolfito_11
    };

    init_animation(npc_1, &animation[npc_1], 0, npc_idle, 1, DEFAULT_ANIMATION_SPEED, 4);
}