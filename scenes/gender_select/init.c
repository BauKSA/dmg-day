#include <gb/gb.h>

#include "../../include/scene.h"
#include "gender_select.h"

#include "../../assets/sprites/backgrounds/template/template.h"

void GenderSelect_Init(Scene *scene)
{
    GenderSelectData *data = malloc(sizeof(GenderSelectData));
    if (!data)
        return;

    data->gender = BOY;
    scene->data = data;

    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);
}