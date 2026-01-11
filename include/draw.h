#pragma once

#include <stdint.h>
#include <gb/gb.h>

#include "entity.h"
#include "position.h"
#include "render.h"
#include "animation.h"

void draw_actor(Entity e)
{
    uint8_t x = position.x[e];
    uint8_t y = position.y[e];

    AnimationComponent *anim_comp = &animation[e];
    Animation *anim = &anim_comp->animations[anim_comp->current];

    uint8_t num_tiles = anim->tiles_per_frame; // 1, 2 o 4
    uint8_t first_tile = anim->start_frame + anim->current_frame * anim->tiles_per_frame;

    uint8_t sprite_ids[4] = {0, 1, 2, 3};

    // Asignar tiles del frame a los sprites
    for (uint8_t i = 0; i < num_tiles; i++)
        set_sprite_tile(sprite_ids[i], first_tile + i);

    // Ahora movemos los sprites según num_tiles
    if (num_tiles == 1)
    {
        move_sprite(sprite_ids[0], x, y);
    }
    else if (num_tiles == 2)
    {
        if (render.vertical[e])
        {
            move_sprite(sprite_ids[0], x, y);
            move_sprite(sprite_ids[1], x, y + 8);
        }
        else
        {
            move_sprite(sprite_ids[0], x, y);
            move_sprite(sprite_ids[1], x + 8, y);
        }
    }
    else if (num_tiles == 4)
    {
        move_sprite(sprite_ids[0], x, y);
        move_sprite(sprite_ids[1], x + 8, y);
        move_sprite(sprite_ids[2], x, y + 8);
        move_sprite(sprite_ids[3], x + 8, y + 8);
    }
}