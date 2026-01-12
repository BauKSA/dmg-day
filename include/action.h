#include <gb/gb.h>

#ifndef ACTION_H
#define ACTION_H

#include "entity.h"
#include "position.h"
#include "player.h"
#include "animation.h"

extern uint8_t MOVE_SPEED;

typedef enum
{
    DIR_NONE,
    DIR_UP,
    DIR_DOWN,
    DIR_LEFT,
    DIR_RIGHT
} Direction;

extern Direction current_direction;

extern uint8_t last_keys;

void move_up(Entity e);

void move_down(Entity e);

void move_left(Entity e);

void move_right(Entity e);

void check_input(void);

#endif // ACTION_H