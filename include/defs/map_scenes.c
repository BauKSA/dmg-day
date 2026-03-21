#include <gb/gb.h>

#include "../all_scenes.h"
#include "../scene.h"

// All scenes include

// MENU
#include "../../scenes/language_select/language_select.h"
#include "../../scenes/gender_select/gender_select.h"
#include "../../scenes/inventory/inventory_scene.h"
#include "../../scenes/main_menu/main_menu.h"
#include "../../scenes/story/story.h"

// MAPAS
#include "../../scenes/map/0-0/map_00.h"
#include "../../scenes/map/0-1/map_01.h"
#include "../../scenes/map/0-2/map_02.h"
#include "../../scenes/map/0-3/map_03.h"

#include "../../scenes/map/1-0/map_10.h"
#include "../../scenes/map/1-1/map_11.h"
#include "../../scenes/map/1-2/map_12.h"
#include "../../scenes/map/1-3/map_13.h"

#include "../../scenes/map/2-0/map_20.h"
#include "../../scenes/map/2-1/map_21.h"
#include "../../scenes/map/2-2/map_22.h"
#include "../../scenes/map/2-3/map_23.h"

#include "../../scenes/map/3-0/map_30.h"
#include "../../scenes/map/3-1/map_31.h"
#include "../../scenes/map/3-2/map_32.h"
#include "../../scenes/map/3-3/map_33.h"

// MINI JUEGOS
#include "../../scenes/mini_games/leaves/mg_leaves.h"
#include "../../scenes/mini_games/homework/mg_homework.h"
#include "../../scenes/mini_games/final/mg_final.h"

#include "../../scenes/game_over/game_over.h"
#include "../../scenes/you_win/you_win.h"

#define MAP_0_BANK 1
#define MAP_1_BANK 2
#define MAP_2_BANK 3
#define MAP_3_BANK 4
#define MENU_BANK 5
#define MG_BANK 6

Scene *scene_manager_MapScene(enum AllScenes scene)
{
  uint8_t _prev_bank = _current_bank;

  vsync();

  switch (scene)
  {
  case MENU:
    SWITCH_ROM_MBC1(MENU_BANK);
    MainMenu_Create();
    return &MainMenu;
    SWITCH_ROM_MBC1(_prev_bank);
  case LANG_SELECT:
    SWITCH_ROM_MBC1(MENU_BANK);
    LanguageSelect_Create();
    return &LanguageSelect;
    SWITCH_ROM_MBC1(_prev_bank);
  case GENDER_SELECT:
    SWITCH_ROM_MBC1(MENU_BANK);
    GenderSelect_Create();
    return &GenderSelect;
    SWITCH_ROM_MBC1(_prev_bank);
  case INVENTORY:
    SWITCH_ROM_MBC1(MENU_BANK);
    InventoryScene_Create();
    return &InventoryScene;
    SWITCH_ROM_MBC1(_prev_bank);
  case STORY:
    SWITCH_ROM_MBC1(MENU_BANK);
    Story_Create();
    return &Story;
    SWITCH_ROM_MBC1(_prev_bank);

    // MAPAS
  case MAP_00:
    SWITCH_ROM_MBC1(MAP_0_BANK);
    Map_00_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_00;

  case MAP_01:
    SWITCH_ROM_MBC1(MAP_0_BANK);
    Map_01_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_01;

  case MAP_02:
    SWITCH_ROM_MBC1(MAP_0_BANK);
    Map_02_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_02;

  case MAP_03:
    SWITCH_ROM_MBC1(MAP_0_BANK);
    Map_03_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_03;

  case MAP_10:
    SWITCH_ROM_MBC1(MAP_1_BANK);
    Map_10_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_10;

  case MAP_11:
    SWITCH_ROM_MBC1(MAP_1_BANK);
    Map_11_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_11;

  case MAP_12:
    SWITCH_ROM_MBC1(MAP_1_BANK);
    Map_12_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_12;

  case MAP_13:
    SWITCH_ROM_MBC1(MAP_1_BANK);
    Map_13_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_13;

  case MAP_20:
    SWITCH_ROM_MBC1(7); // NO ENTRABA MÁS EN EL 3
    Map_20_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_20;

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
    SWITCH_ROM_MBC1(MENU_BANK); // NO ENTRABA MÁS EN EL 4
    Map_33_Create();
    SWITCH_ROM_MBC1(_prev_bank);

    return &Map_33;

  // MINI JUEGOS
  case MG_LEAVES:
    SWITCH_ROM_MBC1(MG_BANK);
    Mg_Leaves_Create();
    return &Mg_Leaves;
  case MG_HOMEWORK:
    SWITCH_ROM_MBC1(MG_BANK);
    Mg_Homework_Create();
    return &Mg_Homework;
  case MG_FINAL:
    SWITCH_ROM_MBC1(MG_BANK);
    Mg_Final_Create();
    return &Mg_Final;

  case GAME_OVER:
    SWITCH_ROM_MBC1(7);
    GameOver_Create();
    return &GameOver;

      case YOU_WIN:
    SWITCH_ROM_MBC1(7);
    YouWin_Create();
    return &YouWin;
  default:
    return NULL;
  }
}
