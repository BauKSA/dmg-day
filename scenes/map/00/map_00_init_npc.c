#include "./map_00.h"
#include "../map_data.h"
#include "../../../assets/sprites/NPCs/example/example_npc.h"
#include "../../../include/animation.h"
#include "../../../include/entity.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../../../include/load.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"

void Map_00_NPC_Init(Scene *scene)
{
    position.x[npc_1] = 40;
    position.y[npc_1] = 80;

    char npc_name[10] = "npc 1";
    for (size_t i = 0; npc_name[i] != '\n'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_y[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 4;
    render.vertical[npc_1] = TRUE;

    // PLAYER DOWN ANIMATIONS
    const unsigned char *npc_idle[] = {
        spr_example_NPC_00,
        spr_example_NPC_10,
        spr_example_NPC_01,
        spr_example_NPC_11};

    init_animation(npc_1, &animation[npc_1], 0, npc_idle, 1, DEFAULT_ANIMATION_SPEED, 4);
}