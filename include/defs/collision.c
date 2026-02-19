#include "../collision.h"

uint8_t check_collision(
    uint8_t x1, uint8_t y1,
    uint8_t x2, uint8_t y2, uint8_t size)
{
    return (
        x1 < x2 + size &&
        x1 + size > x2 &&
        y1 < y2 + size &&
        y1 + size > y2);
}
