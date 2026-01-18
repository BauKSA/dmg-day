#include <gb/gb.h>

#include "inventory_scene.h"
#include "../../include/scene.h"

#include "../../assets/sprites/backgrounds/inventory/inventory_bkg.h"

void InventoryScene_Init(Scene *scene, Entity *player)
{
    scene->data = NULL;

    set_bkg_data(0, inventory_bkg_tileset_size, inventory_bkg_tileset);
    set_bkg_tiles(0, 0, 20, 18, inventory_bkg_tilemap);
}