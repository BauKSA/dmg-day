#include "./main_menu.h"
#include "../../include/scene.h"

Scene MainMenu;
uint16_t timer = 0;
uint8_t rate = 45;
uint8_t show_text = 1;

void MainMenu_Create(void){
    MainMenu.init = MainMenu_Init;
    MainMenu.update = MainMenu_Update;
    
    MainMenu.data = NULL;
}