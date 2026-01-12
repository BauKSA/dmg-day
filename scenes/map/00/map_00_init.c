#include <gb/gb.h>

#include "../../../include/scene.h"
#include "map_00.h"

#include "../../../assets/sprites/backgrounds/template/template.h"
#include "../map_data.h"

void Map_00_Init(Scene *scene, Entity* player)
{
    MapData *data = malloc(sizeof(MapData));
    if (!data)
        return;

    data->player = player;
    scene->data = data;

    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);
}