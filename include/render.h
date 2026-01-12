#pragma once

#ifndef RENDER_H
#define RENDER_H

#include <gb/gb.h>
#include <stdint.h>
#include <stdbool.h>

#include "entity.h"

#define MAX_TILES_PER_ACTOR 4

typedef struct {
    uint8_t tile_start[MAX_ENTITIES];
    uint8_t tile_count[MAX_ENTITIES];
    bool vertical[MAX_ENTITIES];
} RenderComponent;

extern RenderComponent render;

void render_reset(Entity e);

#endif // RENDER_H