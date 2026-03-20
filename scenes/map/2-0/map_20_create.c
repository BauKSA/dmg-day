#pragma bank 7

#include "map_20.h"
#include "../../../include/scene.h"

void Map_20_Create(void)
{
    Map_20.init = Map_20_Init;
    Map_20.update = Map_20_Update;
    Map_20.destroy = Map_20_Destroy;
    Map_20.bank = 7;
    Map_20.data = NULL;
}