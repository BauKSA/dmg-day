#include "../npcs.h"
#include "../entity.h"

Entity npc_1;
Entity npc_2;
Entity option_actor;

uint8_t humor_stats[MAX_NPCS];

void init_NPCs()
{
    npc_1 = create_entity();
    npc_2 = create_entity();
    option_actor = create_entity();
}