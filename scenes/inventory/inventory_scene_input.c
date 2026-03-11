#pragma bank 5

#include "inventory_scene.h"
#include "../../include/input.h"
#include "../../include/language.h"
#include "../../include/inventory.h"
#include "../../include/position.h"
#include "../../include/npcs.h"
#include "../../include/draw.h"
#include "../../include/player.h"
#include "../../include/npcs.h"
#include "../../include/scene_manager.h"
#include "../../include/all_scenes.h"
#include "../../include/char_to_tile.h"
#include "../../include/text_positions.h"
#include "../map/map_data.h"

#include "../../assets/chars/chars.h"

#include <gb/gb.h>

void InventoryScene_CheckInput()
{
    if (!(keys & J_SELECT) && (prev_keys & J_SELECT))
        next_scene = prev_scene;

    if (!(keys & J_LEFT) && (prev_keys & J_LEFT))
    {
        if (selected_item_index == 0)
            return;

        selected_item_index--;
        position.x[option_actor] -= 24;
    }

    if (!(keys & J_RIGHT) && (prev_keys & J_RIGHT))
    {
        if (selected_item_index == MAX_ITEMS - 1)
            return;

        selected_item_index++;
        position.x[option_actor] += 24;
    }

    if ((keys & J_A) && !(prev_keys & J_A))
    {
        active_item_index = selected_item_index;
        active_item = 1;

        next_scene = prev_scene;
    }

    return;
}