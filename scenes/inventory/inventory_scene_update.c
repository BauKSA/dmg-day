#include "inventory_scene.h"
#include "../../include/inventory.h"

#include "../../include/draw.h"
#include "../../include/npcs.h"
#include "../../include/scene.h"

void InventoryScene_Update(Scene* scene){
    draw_actor(option_actor);
    inventory_input();
}