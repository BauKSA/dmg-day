#pragma bank 2

#include "map_11.h"
#include "../../../include/scene.h"

void Map_11_Create(void)
{
    Map_11.init = Map_11_Init;
    Map_11.update = Map_11_Update;
    Map_11.bank = 2;
    Map_11.data = NULL;
}