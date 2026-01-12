#include "map_00.h"
#include "../../../include/scene.h"

Scene Map_00;

void Map_00_Create(void){
    Map_00.init = Map_00_Init;
    Map_00.update = Map_00_Update;
    
    Map_00.data = NULL;
}