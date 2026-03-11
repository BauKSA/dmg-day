#pragma bank 3

#include "map_22.h"

#include "../../../include/inventory.h"
#include "../item_no_use.h"

void Map_22_CheckItems()
{
    if (active_item == 0)
        return;

    active_item = 0;
    ItemNoUseText();
}