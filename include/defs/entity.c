#include <stdint.h>

#include "../entity.h"

Entity next_entity_id = 0;

Entity create_entity()
{
    return next_entity_id++;
}