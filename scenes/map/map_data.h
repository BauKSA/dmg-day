#include "../../include/entity.h"
#include "../../include/scene.h"
#include "../../include/all_scenes.h"

#ifndef MAP_DATA_H
#define MAP_DATA_H

#define MAP_WIDTH 20
#define MAP_HEIGHT 18

/**
 * Colision map values:
 * 0: walkable
 * 1: not walkable
 * 2 - 5: event trigger
 * 6 - 9: spawner trigger
 * 
 * Spawner values:
 * 6: right spawner
 * 7: left spawner
 * 8: up spawner
 * 9: down spawner
 */ 

typedef void (*CollisionEvent)();

typedef struct MapSpawner{
  enum AllScenes right;
  enum AllScenes left;
  enum AllScenes up;
  enum AllScenes down;
} MapSpawner;

typedef struct MapData {
  Entity npc[MAX_NPCS_PER_SCENE];
  uint8_t npc_count;
  Entity player;
  const uint8_t (*collision_map)[MAP_WIDTH];
  CollisionEvent events[MAX_EVENTS];
  uint8_t event_count;
  uint8_t event_active;
  MapSpawner spawner;
} MapData;

void Map_Collision(Scene *scene);
void clean();

extern MapData CurrentMapData;
extern const uint8_t empty_tile;

#endif // MAP_DATA_H
