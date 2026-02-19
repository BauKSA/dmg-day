#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

typedef uint8_t Entity;

#define MAX_ENTITIES 7
#define SCENE_ENTITY 4

extern Entity next_entity_id;

Entity create_entity(void);
void reset_entities(void);

#endif // ENTITY_H