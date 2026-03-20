#pragma bank 6

#include "mg_final.h"

#include "../mg_load_screen.h"

#include "../../../include/scene.h"
#include "../../../include/minigames.h"

void Mg_Final_Create(void)
{
    Mg_Final.init = Mg_Final_Init;
    Mg_Final.update = Mg_Final_Update;
    Mg_Final.bank = 6;
    Mg_Final.data = NULL;

    mgl_initialized = 0;
}