#include <gb/gb.h>

#include "../../../include/scene.h"
#include "map_00.h"

#include "../../../assets/sprites/backgrounds/map_example/map_example.h"
#include "../../../assets/chars/chars.h"
#include "../map_data.h"
#include "./map_00_collision.h"
#include "../../../include/char_to_tile.h"

void hello_event() {
    char txt[] = "Hello, World!";
    for(size_t i = 0; txt[i] != '\0'; i++){
        uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
        set_bkg_tiles(i + 1, 15, 1, 1, &tile);
    }
}

void Map_00_Init(Scene *scene, Entity player)
{
    CurrentMapData.player = player;
    CurrentMapData.collision_map = map_00_example_collision;
    CurrentMapData.npc[0] = 1;
    CurrentMapData.npc_count = 1;

    CurrentMapData.event_count = 1;
    CurrentMapData.events[0] = hello_event;

    scene->data = &CurrentMapData;
    Map_00_NPC_Init(scene);

    set_bkg_data(0, example_tileset_size, example_tileset);
    set_bkg_tiles(0, 0, 20, 18, example_tilemap);
}