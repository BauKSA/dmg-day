#pragma bank 2

#include "map_13.h"
#include "../../../include/scene.h"

void Map_13_Create(void)
{
    Map_13.init = Map_13_Init;
    Map_13.update = Map_13_Update;
    Map_13.bank = 2;
    Map_13.data = NULL;
}