#include <gb/gb.h>

#include "../../include/action.h"
#include "../../include/all_scenes.h"
#include "../../include/input.h"
#include "../../include/player.h"
#include "../../include/scene_manager.h"
#include "./map_player_movement.h"

void Map_PlayerMovement() {
  if (!(keys & J_SELECT) && (prev_keys & J_SELECT)) {
    cache_player_position();

    scene_manager.change_scene(INVENTORY, &player);
  }

  // Si no hay dirección activa, asignamos la primera que se presiona
  if (current_direction == DIR_NONE) {
    if (keys & J_UP)
      current_direction = DIR_UP;
    else if (keys & J_DOWN)
      current_direction = DIR_DOWN;
    else if (keys & J_LEFT)
      current_direction = DIR_LEFT;
    else if (keys & J_RIGHT)
      current_direction = DIR_RIGHT;
  }

  // Ejecutar la dirección activa
  switch (current_direction) {
  case DIR_UP:
    move_up(player);
    set_animation(&animation[player], player_animations.UP_WALKING);
    break;
  case DIR_DOWN:
    move_down(player);
    set_animation(&animation[player], player_animations.DOWN_WALKING);
    break;
  case DIR_LEFT:
    move_left(player);
    break;
  case DIR_RIGHT:
    move_right(player);
    break;
  default:
    break;
  }

  // Si se suelta la dirección activa, ponemos DIR_NONE
  if (current_direction == DIR_UP && !(keys & J_UP)) {
    current_direction = DIR_NONE;
    set_animation(&animation[player], player_animations.UP_STAY);
  }

  if (current_direction == DIR_DOWN && !(keys & J_DOWN)) {
    current_direction = DIR_NONE;
    set_animation(&animation[player], player_animations.DOWN_STAY);
  }

  if (current_direction == DIR_LEFT && !(keys & J_LEFT))
    current_direction = DIR_NONE;
  if (current_direction == DIR_RIGHT && !(keys & J_RIGHT))
    current_direction = DIR_NONE;
}
