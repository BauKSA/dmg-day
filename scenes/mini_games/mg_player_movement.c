#include <gb/gb.h>

#include "../../include/action.h"
#include "../../include/input.h"
#include "../../include/player.h"
#include "../../include/scene_manager.h"
#include "./mg_player_movement.h"

void Mg_PlayerMovement(uint8_t horizontal, uint8_t vertical) {
  // Si no hay dirección activa, asignamos la primera que se presiona
  if (current_direction == DIR_NONE) {
    if (keys & J_UP && vertical != 0)
      current_direction = DIR_UP;
    else if (keys & J_DOWN && vertical != 0)
      current_direction = DIR_DOWN;
    else if (keys & J_LEFT && horizontal != 0)
      current_direction = DIR_LEFT;
    else if (keys & J_RIGHT && horizontal != 0)
      current_direction = DIR_RIGHT;
  }

  // Ejecutar la dirección activa
  switch (current_direction) {
  case DIR_UP:
    move_up(mg_player);
    break;
  case DIR_DOWN:
    move_down(mg_player);
    break;
  case DIR_LEFT:
    move_left(mg_player);
    break;
  case DIR_RIGHT:
    move_right(mg_player);
    break;
  default:
    break;
  }

  // Si se suelta la dirección activa, ponemos DIR_NONE
  if (current_direction == DIR_UP && !(keys & J_UP))
    current_direction = DIR_NONE;

  if (current_direction == DIR_DOWN && !(keys & J_DOWN))
    current_direction = DIR_NONE;

  if (current_direction == DIR_LEFT && !(keys & J_LEFT))
    current_direction = DIR_NONE;

  if (current_direction == DIR_RIGHT && !(keys & J_RIGHT))
    current_direction = DIR_NONE;
}
