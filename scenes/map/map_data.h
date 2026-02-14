#include "../../include/entity.h"
#include "../../include/scene.h"

#ifndef MAP_DATA_H
#define MAP_DATA_H

#define MAP_WIDTH 20
#define MAP_HEIGHT 18

#define MAX_NPCS 2

#define MAX_EVENTS 5

typedef void (*CollisionEvent)();

typedef struct MapData {
    Entity npc[MAX_NPCS];
    uint8_t npc_count;
    Entity player;
    const uint8_t (*collision_map)[MAP_WIDTH];
    CollisionEvent events[MAX_EVENTS];
    uint8_t event_count;
    uint8_t event_active;
} MapData;

void Map_Collision(Scene *scene);
void clean();

extern MapData CurrentMapData;
extern const uint8_t empty_tile;

#endif // MAP_DATA_H