#include <gb/gb.h>

#include "inventory_scene.h"
#include "../../include/scene.h"

#include "../../assets/sprites/backgrounds/inventory/inventory_bkg.h"
#include "../../assets/sprites/inventory/items/branch/spr_Branch.h"

void InventoryScene_Init(Scene *scene, Entity player)
{
    scene->data = NULL;

    unsigned char tile = 51;

    set_bkg_data(0, inventory_bkg_tileset_size, inventory_bkg_tileset);
    set_bkg_tiles(0, 0, 20, 18, inventory_bkg_tilemap);

    set_bkg_data(51, 1, spr_Branch);
    set_bkg_tiles(5, 7, 1, 1, &tile);
}