#include "../render.h"

RenderComponent render;

void render_reset(Entity e) {
    render.tile_start[e] = 0xFF;
    render.tile_count[e] = 0;
}