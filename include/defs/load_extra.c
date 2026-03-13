#pragma bank 6

#include "../load.h"
#include "../extra_actor.h"

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