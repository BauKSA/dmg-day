#include "../inventory.h"

#include "../draw.h"
#include "../input.h"
#include "../npcs.h"
#include "../player.h"
#include "../scene_manager.h"

// Limits
const uint8_t top_limit = 72;
const uint8_t bottom_limit = 96;

const uint8_t left_limit = 56;
const uint8_t right_limit = 128;

const uint8_t VERTICAL_MOVEMENT = 24;
const uint8_t HORIZONTAL_MOVEMENT = 24;

void inventory_input() {
  if (!(keys & J_SELECT) && (prev_keys & J_SELECT)) {
    position.y[option_actor] = 0;
    draw_actor(option_actor);

    selected_item = ITM_NONE;

    scene_manager->change_scene(MAP_00, player);
  }

  uint8_t arrow_x = position.x[option_actor];
  uint8_t arrow_y = position.y[option_actor];

  if ((prev_keys & J_UP) && !(keys & J_UP)) {
    arrow_y -= VERTICAL_MOVEMENT;
    selected_item -= INVENTORY_ITEMS / 2;
  } else if ((prev_keys & J_DOWN) && !(keys & J_DOWN)) {
    arrow_y += VERTICAL_MOVEMENT;
    selected_item -= INVENTORY_ITEMS / 2;
  } else if ((prev_keys & J_RIGHT) && !(keys & J_RIGHT)) {
    arrow_x += HORIZONTAL_MOVEMENT;
    selected_item++;
  } else if ((prev_keys & J_LEFT) && !(keys & J_LEFT)) {
    arrow_x -= HORIZONTAL_MOVEMENT;
    selected_item--;
  }

  if (arrow_y > bottom_limit) {
    arrow_y = bottom_limit;
    selected_item -= INVENTORY_ITEMS / 2;
  }
  if (arrow_y < top_limit) {
    arrow_y = top_limit;
    selected_item += INVENTORY_ITEMS / 2;
  }

  if (arrow_x > right_limit) {
    arrow_x = right_limit;
    selected_item--;
  }
  if (arrow_x < left_limit) {
    arrow_x = left_limit;
    selected_item++;
  }

  position.y[option_actor] = arrow_y;
  position.x[option_actor] = arrow_x;
}
