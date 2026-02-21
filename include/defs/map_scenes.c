#include <gb/gb.h>

#include "../all_scenes.h"
#include "../scene.h"

// All scenes include
#include "../../scenes/gender_select/gender_select.h"
#include "../../scenes/inventory/inventory_scene.h"
#include "../../scenes/main_menu/main_menu.h"

// MAPAS
#include "../../scenes/map/00/map_00.h"

// MINI JUEGOS
#include "../../scenes/mini_games/leaves/mg_leaves.h"

Scene *scene_manager_MapScene(enum AllScenes scene)
{
    switch (scene)
    {
    case MENU:
        MainMenu_Create();
        return &MainMenu;
    case GENDER_SELECT:
        GenderSelect_Create();
        return &GenderSelect;
    case INVENTORY:
        InventoryScene_Create();
        return &InventoryScene;

    // MAPAS
    case MAP_00:
        Map_00_Create();
        return &Map_00;
    // MINI JUEGOS
    case MG_LEAVES:
        Mg_Leaves_Create();
        return &Mg_Leaves;
    default:
        return NULL;
    }
}
