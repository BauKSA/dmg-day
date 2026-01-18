#include "../inventory.h"

uint8_t prev_keys = 0;

// Limits
const uint8_t top_limit = 72;
const uint8_t bottom_limit = 104;

const uint8_t left_limit = 56;
const uint8_t right_limit = 128;

const uint8_t VERTICAL_MOVEMENT = 32;
const uint8_t HORIZONTAL_MOVEMENT = 24;

void inventory_input()
{
    uint8_t keys = joypad();

    uint8_t arrow_x = position.x[arrow];
    uint8_t arrow_y = position.y[arrow];

    if ((prev_keys & J_UP) && !(keys & J_UP))
    {
        arrow_y -= VERTICAL_MOVEMENT;
    }
    else if ((prev_keys & J_DOWN) && !(keys & J_DOWN))
    {
        arrow_y += VERTICAL_MOVEMENT;
    }
    else if ((prev_keys & J_RIGHT) && !(keys & J_RIGHT))
    {
        arrow_x += HORIZONTAL_MOVEMENT;
    }
    else if ((prev_keys & J_LEFT) && !(keys & J_LEFT))
    {
        arrow_x -= HORIZONTAL_MOVEMENT;
    }

    if (arrow_y > bottom_limit)
        arrow_y = bottom_limit;
    if (arrow_y < top_limit)
        arrow_y = top_limit;

    if (arrow_x > right_limit)
        arrow_x = right_limit;
    if (arrow_x < left_limit)
        arrow_x = left_limit;

    position.y[arrow] = arrow_y;
    position.x[arrow] = arrow_x;

    prev_keys = keys;
}