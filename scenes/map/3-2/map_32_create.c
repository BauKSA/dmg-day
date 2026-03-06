#pragma bank 2

#include "./map_32.h"
#include "../../../include/scene.h"

void Map_32_Create() {
  Map_32.init = Map_32_Init;
  Map_32.update = Map_32_Update;
  Map_32.bank = 2;
}
