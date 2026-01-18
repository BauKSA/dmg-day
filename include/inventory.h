#ifndef INVENTORY_H
#define INVENTORY_H

#include <stdint.h>
#include <stdbool.h>
#include <gb/gb.h>

#include "entity.h"
#include "position.h"
#include "render.h"
#include "load.h"
#include "animation.h"

typedef struct InventorySlot
{
    uint8_t item;
    bool active;
} InventorySlot;

extern Entity arrow;

void init_arrow(void);

void inventory_input();

#endif // INVENTORY_H