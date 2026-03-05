#include "map_22.h"
#include "../../../include/scene.h"

Scene Map_22;

void Map_22_Create(void)
{
    Map_22.init = Map_22_Init;
    Map_22.update = Map_22_Update;
    Map_22.bank = 1;
    Map_22.data = NULL;
}