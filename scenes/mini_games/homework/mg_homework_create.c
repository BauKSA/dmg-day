#pragma bank 6

#include "mg_homework.h"

#include "./mg_load_screen.h"

#include "../../../include/scene.h"
#include "../../../include/minigames.h"

void Mg_Homework_Create(void)
{
    Mg_Homework.init = Mg_Homework_Init;
    Mg_Homework.update = Mg_Homework_Update;
    Mg_Homework.bank = 6;
    Mg_Homework.data = NULL;

    mgl_initialized = 0;
}