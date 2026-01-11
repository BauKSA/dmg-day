#pragma once

#include <stdint.h>

typedef uint16_t Entity;

#define MAX_ENTITIES 128
static Entity next_entity_id = 0;

Entity create_entity(void) {
    return next_entity_id++;
}