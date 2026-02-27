#include <gb/gb.h>
#include <stdint.h>

#include "../../include/can_move.h"
#include "../../include/position.h"
#include "../../include/scene.h"
#include "../../scenes/map/map_data.h"

static inline uint8_t get_tile(MapData *data, int x, int y) {
  return data->collision_map[y * MAP_WIDTH + x];
}

// Función de colisión con debug visual
void Map_Collision(Scene *scene) {
  MapData *data = (MapData *)scene->data;
  Entity player = data->player;

  uint8_t tile_x = (position.x[player]) >> 3;
  uint8_t tile_y = (position.y[player]) >> 3;

  actual_tile.x = tile_x;
  actual_tile.y = tile_y;
  actual_tile.value = data->collision_map[tile_y][tile_x];

  can_move.right = (data->collision_map[tile_y][tile_x + 1] != 1);
  can_move.left = (data->collision_map[tile_y][tile_x - 1] != 1);
  can_move.up = (data->collision_map[tile_y - 1][tile_x] != 1);
  can_move.down = (data->collision_map[tile_y + 1][tile_x] != 1);

  /**
   * Eventos
   */

  if (data->collision_map[tile_y][tile_x] == 0 &
      CurrentMapData.event_active == 1) {
    clean();
  }

  if (data->collision_map[tile_y][tile_x] != 0) {
    uint8_t event = data->collision_map[tile_y][tile_x];
    event -= 2;

    if (event >= data->event_count || event >= MAX_EVENTS)
      return;

    if (data->events[event] == NULL)
      return;

    data->events[event]();
  }
}
