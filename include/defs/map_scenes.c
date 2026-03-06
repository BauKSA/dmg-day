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

#include "../../scenes/map/3-0/map_30.h"
#include "../../scenes/map/3-1/map_31.h"
#include "../../scenes/map/3-2/map_32.h"
#include "../../scenes/map/3-3/map_33.h"

// MINI JUEGOS
#include "../../scenes/mini_games/leaves/mg_leaves.h"

#define MAP_0_BANK 1
#define MAP_1_BANK 2
#define MAP_2_BANK 3
#define MAP_3_BANK 4

Scene *scene_manager_MapScene(enum AllScenes scene)
{
  uint8_t _prev_bank = _current_bank;

  vsync();

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
    SWITCH_ROM_MBC1(MAP_2_BANK);
    Map_21_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_21;
  case MAP_22:
    SWITCH_ROM_MBC1(MAP_2_BANK);
    Map_22_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_22;
  case MAP_23:
    SWITCH_ROM_MBC1(MAP_2_BANK);
    Map_23_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_23;

  case MAP_30:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_30_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_30;

  case MAP_31:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_31_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_31;

  case MAP_32:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_32_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_32;
  case MAP_33:
    SWITCH_ROM_MBC1(MAP_3_BANK);
    Map_33_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_33;

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
