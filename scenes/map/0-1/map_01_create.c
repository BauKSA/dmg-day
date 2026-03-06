#pragma bank 1

#include "map_01.h"
#include "../../../include/scene.h"

void Map_01_Create(void)
{
    Map_01.init = Map_01_Init;
    Map_01.update = Map_01_Update;
    Map_01.bank = 1;
    Map_01.data = NULL;
}