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

#define INVENTORY_ITEMS_START 53
#define INVENTORY_COIN_STARTS_X 5
#define INVENTORY_COIN_STARTS_Y 12

typedef struct InventorySlot
{
    uint8_t item;
    bool active;
} InventorySlot;

void init_arrow(void);
void inventory_input();

extern uint8_t inventory_active;

#endif // INVENTORY_H