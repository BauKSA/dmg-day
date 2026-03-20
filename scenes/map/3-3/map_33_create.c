#pragma bank 5

#include "./map_33.h"
#include "../../../include/scene.h"

void Map_33_Create()
{
  Map_33.init = Map_33_Init;
  Map_33.update = Map_33_Update;
  Map_33.destroy = Map_33_Destroy;
  Map_33.bank = 5;
}
