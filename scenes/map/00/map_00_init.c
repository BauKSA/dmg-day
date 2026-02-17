#include <gb/gb.h>

#include "../../../include/scene.h"
#include "../../../include/player.h"
#include "../../../include/position.h"
#include "map_00.h"

#include "../../../assets/sprites/backgrounds/map_example/map_example.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/chars/numbers.h"
#include "../map_data.h"
#include "./map_00_collision.h"
#include "../../../include/char_to_tile.h"
#include "../../../include/text_positions.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/npc_stats_map.h"

void hello_event()
{
    if (CurrentMapData.event_active == 1)
        return;

    CurrentMapData.event_active = 1;
    char txt[] = "hello, world!";
    Scene_DrawNPCLine(npc_1, (uint8_t)EXAMPLE_00, txt, "\0", 0, NONE);
}

void Map_00_Init(Scene *scene, Entity scene_player)
{
    position.y[player] = player_y_cache;
    CurrentMapData.player = scene_player;
    CurrentMapData.collision_map = map_00_example_collision;
    CurrentMapData.npc[0] = 1;
    CurrentMapData.npc_count = 1;

    CurrentMapData.event_count = 1;
    CurrentMapData.events[0] = hello_event;
    CurrentMapData.event_active = 0;

    scene->data = &CurrentMapData;
    Map_00_NPC_Init(scene);

    set_bkg_data(0, example_tileset_size, example_tileset);
    set_bkg_tiles(0, 0, 20, 18, example_tilemap);
}