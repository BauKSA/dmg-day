#include <stdint.h>

#include "entity.h"
#include "load.h"

#ifndef ANIMATION_H
#define ANIMATION_H

#define MAX_ANIMATIONS 8
#define MAX_FRAMES 4
#define DEFAULT_ANIMATION_SPEED 12

typedef struct
{
    uint8_t start_frame;     // índice inicial en VRAM de esta animación
    uint8_t frame_count;     // cantidad de frames
    uint8_t current_frame;   // frame actual
    uint8_t speed;           // cada cuántos ticks avanza
    uint8_t tick;            // contador interno
    uint8_t tiles_per_frame; // cuántos tiles tiene cada frame
} Animation;

typedef struct
{
    Animation animations[MAX_ANIMATIONS];
    uint8_t current; // índice de animación actual
} AnimationComponent;

extern AnimationComponent animation[MAX_ENTITIES];

void init_animation(
    Entity e,
    AnimationComponent *component, uint8_t anim_index,
    uint8_t *frames[], uint8_t frame_count, uint8_t speed, uint8_t tiles);

void update_animation(AnimationComponent *anim_comp);

void set_animation(AnimationComponent *anim_comp, uint8_t anim_index);

#endif // ANIMATION_H