#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>

typedef uint16_t Entity;

#define MAX_ENTITIES 128
extern Entity next_entity_id;

Entity create_entity(void);

#endif // ENTITY_H