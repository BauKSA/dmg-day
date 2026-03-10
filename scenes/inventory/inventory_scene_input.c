#pragma bank 5

#include "inventory_scene.h"
#include "../../include/input.h"
#include "../../include/language.h"
#include "../../include/position.h"
#include "../../include/npcs.h"
#include "../../include/draw.h"
#include "../../include/player.h"
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

    return;
}