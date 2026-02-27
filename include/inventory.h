#ifndef INVENTORY_H
#define INVENTORY_H

#include <gb/gb.h>
#include <stdint.h>

#include "animation.h"

#define INVENTORY_ITEMS_START 53
#define INVENTORY_COIN_STARTS_X 5
#define INVENTORY_COIN_STARTS_Y 12

// Esto debería ir cambiando a medida que
// se agreguen items. El total es 8, pero lo bajo
// para poder debugear los primeros
#define INVENTORY_ITEMS 4

typedef enum InventoryItem {
  BRANCH,
  BREAD,
  CHOCOLATE,
  GLASSES,

  COUNT
} InventoryItem;

typedef struct InventorySlot {
  InventoryItem item;
  uint8_t active;
} InventorySlot;

void init_arrow(void);
void inventory_input();
void initialize_inventory(void);

extern uint8_t inventory_active;
extern InventorySlot inventory[INVENTORY_ITEMS];

#endif // INVENTORY_H
