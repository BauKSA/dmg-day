#include <stdint.h>

#include "../entity.h"

Entity next_entity_id = 0;

Entity create_entity()
{
    if(next_entity_id >= MAX_ENTITIES) {
        return 0;
    }

    return next_entity_id++;
}

void reset_entities()
{
    next_entity_id = 1;
}