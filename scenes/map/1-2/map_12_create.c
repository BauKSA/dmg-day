#pragma bank 2

#include "map_12.h"
#include "../../../include/scene.h"

void Map_12_Create(void)
{
    Map_12.init = Map_12_Init;
    Map_12.update = Map_12_Update;
    Map_12.bank = 2;
    Map_12.data = NULL;
}