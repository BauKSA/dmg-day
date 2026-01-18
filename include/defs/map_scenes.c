#include "../all_scenes.h"
#include "../scene.h"

// All scenes include
#include "../../scenes/gender_select/gender_select.h"
#include "../../scenes/inventory/inventory_scene.h"
#include "../../scenes/map/00/map_00.h"

Scene *scene_manager_MapScene(enum AllScenes scene)
{
    switch (scene)
    {
    case GENDER_SELECT:
        GenderSelect_Create();
        return &GenderSelect;
    case INVENTORY:
        InventoryScene_Create();
        return &InventoryScene;
    case MAP_00:
        Map_00_Create();
        return &Map_00;
    default:
        return NULL;
    }
}
