#pragma bank 2

#include "./map_31.h"
#include "../../../include/scene.h"

void Map_31_Create() {
  Map_31.init = Map_31_Init;
  Map_31.update = Map_31_Update;
  Map_31.bank = 2;
}
