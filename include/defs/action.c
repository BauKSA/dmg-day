#include "../action.h"

#include "../player.h"
#include "../scene_manager.h"
#include "../can_move.h"

uint8_t MOVE_SPEED = 128;

Direction current_direction = DIR_NONE;

uint8_t last_keys = 0;

void move_up(Entity e)
{
    if (can_move.up == false)
        return;

    position.fixed_y[e] -= MOVE_SPEED;
    position.y[e] = position.fixed_y[e] >> 8;
}

void move_down(Entity e)
{
    if (can_move.down == false)
        return;

    position.fixed_y[e] += MOVE_SPEED;
    position.y[e] = position.fixed_y[e] >> 8;
}

void move_left(Entity e)
{
    if (can_move.left == false)
        return;

    position.fixed_x[e] -= MOVE_SPEED;
    position.x[e] = position.fixed_x[e] >> 8;
}

void move_right(Entity e)
{
    if (can_move.right == false)
        return;

    position.fixed_x[e] += MOVE_SPEED;
    position.x[e] = position.fixed_x[e] >> 8;
}

void check_input(void)
{
    uint8_t keys = joypad();

    if (!(keys & J_SELECT) && (last_keys & J_SELECT))
    {
        scene_manager->change_scene(INVENTORY, player);
    }

    // Si no hay dirección activa, asignamos la primera que se presiona
    if (current_direction == DIR_NONE)
    {
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
    switch (current_direction)
    {
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
    if (current_direction == DIR_UP && !(keys & J_UP))
    {
        current_direction = DIR_NONE;
        set_animation(&animation[player], player_animations.UP_STAY);
    }

    if (current_direction == DIR_DOWN && !(keys & J_DOWN))
    {
        current_direction = DIR_NONE;
        set_animation(&animation[player], player_animations.DOWN_STAY);
    }

    if (current_direction == DIR_LEFT && !(keys & J_LEFT))
        current_direction = DIR_NONE;
    if (current_direction == DIR_RIGHT && !(keys & J_RIGHT))
        current_direction = DIR_NONE;

    last_keys = keys;
}