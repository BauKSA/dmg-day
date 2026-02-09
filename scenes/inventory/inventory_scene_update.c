#include "inventory_scene.h"
#include "../../include/inventory.h"

#include "../../include/draw.h"

void InventoryScene_Update(Scene* scene){
    inventory_input();
    draw_actor(arrow);
}