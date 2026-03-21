#pragma bank 7

#include "../../include/scene.h"

#include "you_win.h"

void YouWin_Create(void)
{
    YouWin.init = YouWin_Init;
    YouWin.update = YouWin_Update;
    YouWin.bank = 7;
}