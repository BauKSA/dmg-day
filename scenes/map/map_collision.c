#include <gb/gb.h>
#include <stdint.h>

#include "../../include/position.h"
#include "../../scenes/map/map_data.h"
#include "../../include/scene.h"
#include "../../include/can_move.h"
#include "../../include/char_to_tile.h"
#include "../../assets/chars/numbers.h"
#include "../../assets/chars/chars.h"

static inline uint8_t get_tile(MapData *data, int x, int y)
{
    return data->collision_map[y * MAP_WIDTH + x];
}

// Función de colisión con debug visual
void Map_Collision(Scene *scene)
{
    MapData *data = (MapData *)scene->data;
    Entity player = data->player;

    /**
     *
     * DEBUG: Dibuja el mapa de colisión en el fondo usando los tiles de números.
     *
     * */

    uint8_t tile_x = (position.x[player]) >> 3;
    uint8_t tile_y = (position.y[player]) >> 3;

    uint8_t x_tens = tile_x / 10;
    uint8_t x_units = tile_x % 10;
    uint8_t y_tens = tile_y / 10;
    uint8_t y_units = tile_y % 10;

    if (x_tens == 0)
        x_tens = 10;
    if (y_tens == 0)
        y_tens = 10;
    if (x_units == 0)
        x_units = 10;
    if (y_units == 0)
        y_units = 10;

    // // array temporal con los tiles a poner
    // uint8_t x_tiles[2] = {x_tens + NUMBER_TILESET_START, x_units + NUMBER_TILESET_START};
    // uint8_t y_tiles[2] = {y_tens + NUMBER_TILESET_START, y_units + NUMBER_TILESET_START};
    // uint8_t x = char_to_tile('x') + CHARS_TILESET_START;
    // uint8_t left = char_to_tile('l') + CHARS_TILESET_START;
    // uint8_t right = char_to_tile('r') + CHARS_TILESET_START;
    // uint8_t up = char_to_tile('u') + CHARS_TILESET_START;
    // uint8_t down = char_to_tile('d') + CHARS_TILESET_START;

    // uint8_t empty = char_to_tile(':') + CHARS_TILESET_START;
    // uint8_t right_collision_value = (data->collision_map[tile_y][tile_x + 1] == 0 ? 10 : 1) + NUMBER_TILESET_START;
    // uint8_t left_collision_value = (data->collision_map[tile_y][tile_x - 1] == 0 ? 10 : 1) + NUMBER_TILESET_START;
    // uint8_t up_collision_value = (data->collision_map[tile_y - 1][tile_x] == 0 ? 10 : 1) + NUMBER_TILESET_START;
    // uint8_t down_collision_value = (data->collision_map[tile_y + 1][tile_x] == 0 ? 10 : 1) + NUMBER_TILESET_START;

    /**
     * Colisiones para el Player
     */
    can_move.right = (data->collision_map[tile_y][tile_x + 1] != 1);
    can_move.left = (data->collision_map[tile_y][tile_x - 1] != 1);
    can_move.up = (data->collision_map[tile_y - 1][tile_x] != 1);
    can_move.down = (data->collision_map[tile_y + 1][tile_x] != 1);

    // set_bkg_tiles(1, 15, 2, 1, x_tiles); // fila de X
    // set_bkg_tiles(1, 16, 2, 1, y_tiles); // fila de Y
    // set_bkg_tiles(5, 15, 1, 1, &right);
    // set_bkg_tiles(8, 15, 1, 1, &left);
    // set_bkg_tiles(5, 16, 1, 1, &up);
    // set_bkg_tiles(8, 16, 1, 1, &down);

    // set_bkg_tiles(6, 15, 1, 1, &empty);
    // set_bkg_tiles(6, 15, 1, 1, &right_collision_value);
    // set_bkg_tiles(9, 15, 1, 1, &left_collision_value);
    // set_bkg_tiles(6, 16, 1, 1, &up_collision_value);
    // set_bkg_tiles(9, 16, 1, 1, &down_collision_value);

    /**
     * Eventos
     */

    if(data->collision_map[tile_y][tile_x] == 0 & CurrentMapData.event_active == 1){
        clean();
    }

    if (data->collision_map[tile_y][tile_x] != 0)
    {
        uint8_t event = data->collision_map[tile_y][tile_x];
        event -= 2;

        if (event >= data->event_count || event >= MAX_EVENTS)
            return;

        if (data->events[event] == NULL)
            return;

        data->events[event]();
    }
}
