#ifndef _EXTRAACTOR_
#define _EXTRAACTOR_
#include <stdint.h>

#define MAX_EXTRA_ACTORS 20

extern uint8_t extra_actor_index;

typedef struct ExtraActor
{
    uint8_t id;
    uint8_t tile_index;
    uint8_t tile_count;
} ExtraActor;

extern ExtraActor extra_actors[MAX_EXTRA_ACTORS];

#endif //_EXTRAACTOR_