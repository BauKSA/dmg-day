#include <stdint.h>
#include <gb/gb.h>

#include "../load.h"
#include "../extra_actor.h"

uint8_t vram_next_index = 0; // siguiente slot libre en VRAM
uint8_t vram_extra_start = 27;

uint8_t load_actor_tiles(Entity e, const unsigned char *tiles[], uint8_t num_tiles)
{
    uint8_t start = vram_next_index;

    // Cargar los tiles en VRAM
    for (uint8_t i = 0; i < num_tiles; i++)
    {
        set_sprite_data(start + i, 1, tiles[i]);
    }

    // Guardar en RenderComponent
    render.tile_start[e] = start;
    render.tile_count[e] = num_tiles;

    // Actualizar próximo índice libre en VRAM
    vram_next_index += num_tiles;

    return start;
}

uint8_t load_extra_tiles(uint8_t id, const unsigned char *tiles, uint8_t num_tiles)
{
    if (extra_actor_index >= MAX_EXTRA_ACTORS)
        extra_actor_index = 0;

    uint8_t start = vram_extra_start;

    set_sprite_data(start, num_tiles, tiles);

    vram_extra_start += num_tiles;

    ExtraActor actor;
    actor.id = id;
    actor.tile_count = num_tiles;
    actor.tile_index = start;

    extra_actors[extra_actor_index] = actor;

    return extra_actor_index++;
}

void reset_extra_tiles()
{
    vram_extra_start = 20;
}

void reset_render_component(void)
{
    for (Entity e = 0; e < next_entity_id; e++)
    {
        render.tile_start[e] = 0xFF;
        render.tile_count[e] = 0;
    }

    vram_next_index = 0;
}