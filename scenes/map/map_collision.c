#include <gb/gb.h>
#include <stdint.h>

#include "../../include/can_move.h"
#include "../../include/position.h"
#include "../../include/scene.h"
#include "../../include/language.h"
#include "../../include/text_positions.h"
#include "../../include/char_to_tile.h"
#include "../../include/inventory.h"
#include "../../include/scene_manager.h"
#include "../../include/player.h"
#include "../../scenes/map/map_data.h"
#include "../../scenes/map/auto_clean.h"

#include "../../include/text_positions.h"
#include "../../assets/chars/numbers.h"
#include "../../assets/chars/chars.h"

static inline uint8_t get_tile(MapData *data, int x, int y)
{
  return data->collision_map[y * MAP_WIDTH + x];
}

// Función de colisión con debug visual
void Map_Collision(Scene *scene)
{
  uint8_t tile_x = (position.x[player]) >> 3;
  uint8_t tile_y = (position.y[player]) >> 3;

  actual_tile.prev = actual_tile.value;
  actual_tile.x = tile_x;
  actual_tile.y = tile_y;
  actual_tile.value = CurrentMapData.collision_map[tile_y][tile_x];

  can_move.right = (CurrentMapData.collision_map[tile_y][tile_x + 1] != 1);
  can_move.left = (CurrentMapData.collision_map[tile_y][tile_x - 1] != 1);
  can_move.up = (CurrentMapData.collision_map[tile_y - 1][tile_x] != 1);
  can_move.down = (CurrentMapData.collision_map[tile_y + 1][tile_x] != 1);

  // EVENTOS
  if (actual_tile.value != actual_tile.prev)
  {
    clean();
  }

  if (active_item == 1 && CurrentMapData.collision_map[tile_y][tile_x] == 0)
  {
    active_item = 0;
    auto_clean_timer = 0;

    ItemNoUseText();
  }

  if (CurrentMapData.collision_map[tile_y][tile_x] > 1 && CurrentMapData.collision_map[tile_y][tile_x] < 6)
  {
    uint8_t event = CurrentMapData.collision_map[tile_y][tile_x];
    event -= 2;

    if (event >= CurrentMapData.event_count || event >= MAX_EVENTS)
      return;

    if (CurrentMapData.events[event] == NULL)
      return;

    CurrentMapData.events[event]();
  }

  if (CurrentMapData.collision_map[tile_y][tile_x] > 5 && CurrentMapData.collision_map[tile_y][tile_x] < 10)
  {
    switch (CurrentMapData.collision_map[tile_y][tile_x])
    {
    case 6:
      if (CurrentMapData.spawner.right == NONE)
        break;
      position.x[player] = 16;
      cache_player_position();
      next_scene = CurrentMapData.spawner.right;
      break;
    case 7:
      if (CurrentMapData.spawner.left == NONE)
        break;
      position.x[player] = 142;
      cache_player_position();
      next_scene = CurrentMapData.spawner.left;
      break;
    case 8:
      if (CurrentMapData.spawner.up == NONE)
        break;
      position.y[player] = 108;
      cache_player_position();
      next_scene = CurrentMapData.spawner.up;
      break;
    case 9:
      if (CurrentMapData.spawner.down == NONE)
        break;
      position.y[player] = 40;
      cache_player_position();
      next_scene = CurrentMapData.spawner.down;
      break;
    }
  }
}
