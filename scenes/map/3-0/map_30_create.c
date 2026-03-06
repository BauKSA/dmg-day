#pragma bank 4

#include "./map_30.h"
#include "../../../include/scene.h"

void Map_30_Create() {
  Map_30.init = Map_30_Init;
  Map_30.update = Map_30_Update;
  Map_30.bank = 4;
}
