#pragma once

#include <stdint.h>

#ifndef POSITION_H
#define POSITION_H

#include "entity.h"

typedef struct {
  uint8_t x[MAX_ENTITIES];
  uint8_t y[MAX_ENTITIES];
  uint16_t fixed_x[MAX_ENTITIES];
  uint16_t fixed_y[MAX_ENTITIES];
} PositionComponent;

typedef struct {
  uint8_t x[MAX_ENTITIES];
  uint8_t y[MAX_ENTITIES];
  uint16_t fixed_x[MAX_ENTITIES];
  uint16_t fixed_y[MAX_ENTITIES];
  uint8_t active[MAX_ENTITIES];
} PositionCache;

extern PositionComponent position;
extern PositionCache cache;

typedef struct Tile {
  uint8_t x;
  uint8_t y;
  uint8_t value;
  uint8_t prev;
} Tile;

extern Tile actual_tile;

#endif // POSITION_H
