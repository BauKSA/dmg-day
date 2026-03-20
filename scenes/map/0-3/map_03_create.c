#pragma bank 1

#include "map_03.h"
#include "../../../include/scene.h"

void Map_03_Create(void)
{
    Map_03.init = Map_03_Init;
    Map_03.update = Map_03_Update;
    Map_03.destroy = Map_03_Destroy;
    Map_03.bank = 1;
    Map_03.data = NULL;
}