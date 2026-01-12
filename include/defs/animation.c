#include <stdint.h>

#include "../animation.h"

AnimationComponent animation[MAX_ENTITIES];

void init_animation(
    Entity e,
    AnimationComponent *component, uint8_t anim_index,
    uint8_t *frames[], uint8_t frame_count, uint8_t speed, uint8_t tiles)
{
    Animation *animation = &component->animations[anim_index];

    animation->frame_count = frame_count;
    animation->speed = speed;
    animation->tick = 0;
    animation->current_frame = 0;
    animation->tiles_per_frame = tiles;

    // Cargar todos los tiles de la animación en VRAM de una
    animation->start_frame = load_actor_tiles(e, frames, frame_count * tiles);

    // Ahora, para dibujar un frame concreto i:
    for (uint8_t i = 0; i < animation->frame_count; i++)
    {
        uint8_t tile_index = animation->start_frame + i * animation->tiles_per_frame;
        // tile_index es el primer tile del frame i en VRAM
        // renderizás usando tile_index y tiles_per_frame
    }

    // Si es la primera animación que agregamos, la activamos
    if (component->current == 0xFF)
        component->current = anim_index;
}

void update_animation(AnimationComponent *anim_comp)
{
    Animation *anim = &anim_comp->animations[anim_comp->current];

    anim->tick++;
    if (anim->tick >= anim->speed)
    {
        anim->tick = 0;
        anim->current_frame++;
        if (anim->current_frame >= anim->frame_count)
            anim->current_frame = 0;
    }
}

void set_animation(AnimationComponent *anim_comp, uint8_t anim_index)
{
    if (anim_comp->current == anim_index)
        return;
        
    anim_comp->current = anim_index;
    Animation *anim = &anim_comp->animations[anim_index];
    anim->current_frame = 0;
    anim->tick = 0;
}