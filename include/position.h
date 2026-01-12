#pragma once

#include <stdint.h>

#ifndef POSITION_H
#define POSITION_H

#include "entity.h"

typedef struct
{
    uint8_t x[MAX_ENTITIES];
    uint8_t y[MAX_ENTITIES];
    uint16_t fixed_x[MAX_ENTITIES];
    uint16_t fixed_y[MAX_ENTITIES];
} PositionComponent;

extern PositionComponent position;

#endif // POSITION_H