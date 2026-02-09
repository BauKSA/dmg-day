#include <gb/gb.h>

#include "../../include/scene.h"

#include "gender_select.h"

#include "../../assets/sprites/backgrounds/gender_select/gender_select_map.h"

void GenderSelect_Init(Scene *scene, Entity player)
{
    GenderSelectData *data = malloc(sizeof(GenderSelectData));
    if (!data)
        return;

    data->gender = BOY;
    scene->data = data;

    set_bkg_data(0, gender_select_tileset_size, gender_select_tileset);
    set_bkg_tiles(0, 0, 20, 18, gender_select_tilemap);
}