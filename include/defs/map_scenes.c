#include <gb/gb.h>

#include "../all_scenes.h"
#include "../scene.h"

// All scenes include
#include "../../scenes/gender_select/gender_select.h"
#include "../../scenes/inventory/inventory_scene.h"
#include "../../scenes/main_menu/main_menu.h"
#include "../../scenes/story/story.h"

// MAPAS
#include "../../scenes/map/00/map_00.h"

#include "../../scenes/map/2-1/map_21.h"
#include "../../scenes/map/2-2/map_22.h"
#include "../../scenes/map/2-3/map_23.h"

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
  case STORY:
    Story_Create();
    return &Story;

  // MAPAS
  case MAP_21:
    Map_21_Create();
    return &Map_21;
  case MAP_22:
    Map_22_Create();
    return &Map_22;
  case MAP_23:
    Map_23_Create();
    return &Map_23;

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
