#pragma bank 1

#include "map_02.h"
#include "../../../include/scene.h"

void Map_02_Create(void)
{
    Map_02.init = Map_02_Init;
    Map_02.update = Map_02_Update;
    Map_02.bank = 1;
    Map_02.data = NULL;
}