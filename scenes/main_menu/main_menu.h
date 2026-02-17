#ifndef _MAINMENU_
#define _MAINMENU_

#include <stdlib.h>

#include "../../include/game.h"
#include "../../include/entity.h"
#include "../../scenes/main_menu/main_menu.h"

void MainMenu_Init(Scene *scene, Entity scene_player);
void MainMenu_Update(Scene *scene);
void MainMenu_InitRandomStats();

extern Scene MainMenu;

void MainMenu_Create(void);
void MainMenu_CheckInput(void);

extern uint16_t timer;
extern uint8_t rate;
extern uint8_t show_text;
extern unsigned int seed;

inline unsigned int my_rand()
{
    seed = seed * 25173 + 13849;
    return seed;
}

#endif //_MAINMENU_