#pragma once

#ifndef DRAW_H
#define DRAW_H

#include <stdint.h>
#include <gb/gb.h>

#include "entity.h"
#include "position.h"
#include "render.h"
#include "animation.h"

#define SPRITE_LIMIT 36

void draw_actor(Entity e);

#endif // DRAW_H