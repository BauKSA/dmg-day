#pragma bank 5

#include "./main_menu.h"
#include "../../include/scene.h"

void MainMenu_Create(void)
{
    MainMenu.init = MainMenu_Init;
    MainMenu.update = MainMenu_Update;
    MainMenu.destroy = MainMenu_Destroy;
    MainMenu.bank = 5;

    MainMenu.data = NULL;
}