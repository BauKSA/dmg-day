#include <gb/gb.h>

#include "../../../include/scene.h"
#include "map_00.h"

#include "../../../assets/sprites/backgrounds/map_example/map_example.h"
#include "../map_data.h"

void Map_00_Init(Scene *scene, Entity player)
{
    MapData *data = malloc(sizeof(MapData));
    if (!data)
        return;

    data->player = player;
    scene->data = data;

    set_bkg_data(0, example_tileset_size, example_tileset);
    set_bkg_tiles(0, 0, 20, 18, example_tilemap);
}