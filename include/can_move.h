#ifndef _CANMOVE_
#define _CANMOVE_

#include <stdbool.h>

typedef struct CanMove
{
    bool up;
    bool down;
    bool left;
    bool right;
} CanMove;

extern CanMove can_move;

#endif // _CANMOVE_