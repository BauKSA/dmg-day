#include "../inventory.h"
#include "../npcs.h"
#include "../position.h"
#include "../scene.h"

// Sprites
#include "../../assets/sprites/inventory/spr_InventoryArrow_idle.h"

uint8_t inventory_active = 0;
InventorySlot inventory[INVENTORY_ITEMS];

void init_arrow(void) {
  position.x[option_actor] = 56;
  position.y[option_actor] = 72;

  position.fixed_x[option_actor] = position.x[option_actor] << 8;
  position.fixed_y[option_actor] = position.y[option_actor] << 8;

  render.tile_start[option_actor] = 0;
  render.tile_count[option_actor] = 1;
  render.vertical[option_actor] = TRUE;

  const unsigned char *arrow_idle[] = {spr_InventoryArrow_idle};

  init_animation(option_actor, &animation[option_actor], 0, arrow_idle, 1,
                 DEFAULT_ANIMATION_SPEED, 1);
}

void initialize_inventory() {
  for (uint8_t i = 0; i < INVENTORY_ITEMS; i++) {
    InventorySlot slot;
    slot.active = 0;
    slot.item = i;

    // DEBUG
    if (i == 0)
      slot.active = 1;

    inventory[i] = slot;
  }
}
