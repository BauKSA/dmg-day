#pragma bank 2

#include "map_10.h"
#include "../../../include/scene.h"

void Map_10_Create(void)
{
    Map_10.init = Map_10_Init;
    Map_10.update = Map_10_Update;
    Map_10.bank = 2;
    Map_10.data = NULL;
}