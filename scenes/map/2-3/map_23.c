#include "map_23.h"
#include "../../../include/scene.h"

Scene Map_23;

void Map_23_Create() {
  Map_23.init = Map_23_Init;
  Map_23.update = Map_23_Update;
  Map_23.bank = 1;
}
