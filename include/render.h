#pragma once

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

RenderComponent render;

void render_reset(Entity e) {
    render.tile_start[e] = 0xFF;
    render.tile_count[e] = 0;
}