#ifndef _NPCS_
#define _NPCS_
#include "./entity.h"

#define MAX_NPCS 15

extern Entity npc_1;
extern Entity npc_2;
extern Entity option_actor;

void init_NPCs();

extern uint8_t humor_stats[MAX_NPCS];

#endif //_NPCS_