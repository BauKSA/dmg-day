#include "map_21.h"
#include "../../../include/scene.h"

Scene Map_21;

void Map_21_Create(void)
{
    Map_21.init = Map_21_Init;
    Map_21.update = Map_21_Update;
    Map_21.bank = 1;
    Map_21.data = NULL;
}