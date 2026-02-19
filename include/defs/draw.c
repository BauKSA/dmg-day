#include <stdint.h>
#include <gb/gb.h>

#include "../draw.h"
#include "../extra_actor.h"

void draw_actor(Entity e)
{
    uint8_t x = position.x[e];
    uint8_t y = position.y[e];

    AnimationComponent *anim_comp = &animation[e];
    Animation *anim = &anim_comp->animations[anim_comp->current];

    uint8_t num_tiles = anim->tiles_per_frame; // 1, 2 o 4
    uint8_t first_tile = anim->start_frame + anim->current_frame * anim->tiles_per_frame;

    uint8_t base = e * 4;
    uint8_t sprite_ids[4] = {base, base + 1, base + 2, base + 3};

    if (base > SPRITE_LIMIT)
        return;

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

void draw_extra(uint8_t index, uint8_t x, uint8_t y, uint8_t tiles, uint8_t vertical)
{
    // Recuperamos info
    uint8_t tile_start = extra_actors[index].tile_index;

    // --- CORRECCIÓN CRÍTICA ---
    // Las entidades normales usan desde el sprite 0 hasta el (MAX_ENTITIES * 4) - 1.
    // Ejemplo: 7 entidades * 4 sprites = 28 sprites ocupados (del 0 al 27).
    // Los extras deben empezar en el 28.
    
    uint8_t hardware_start_offset = MAX_ENTITIES * 4; 
    
    // Además, para que dos "extras" distintos no se peleen por el mismo sprite,
    // sumamos su index multiplicado por 4 (o por 2 si solo usan 2 tiles).
    // Asumiremos que reservamos 4 sprites por extra para simplificar lógica, 
    // igual que con las entidades.
    
    uint8_t base = hardware_start_offset + (index * 4);

    // Límite de Game Boy es 40 sprites
    if (base + tiles > 40)
        return;

    // Asignar tiles
    for (uint8_t i = 0; i < tiles; i++)
        set_sprite_tile(base + i, tile_start + i);

    // Mover sprites
    if (tiles == 1)
    {
        move_sprite(base, x, y);
    }
    else if (tiles == 2)
    {
        if (vertical == 1)
        {
            move_sprite(base, x, y);
            move_sprite(base + 1, x, y + 8);
        }
        else
        {
            move_sprite(base, x, y);
            move_sprite(base + 1, x + 8, y);
        }
    }
    else if (tiles == 4)
    {
        move_sprite(base, x, y);
        move_sprite(base + 1, x + 8, y);
        move_sprite(base + 2, x, y + 8);
        move_sprite(base + 3, x + 8, y + 8);
    }
}