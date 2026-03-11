#pragma bank 5

#include "inventory_scene.h"
#include "../../include/scene.h"
#include "../../include/inventory.h"
#include "../../include/draw.h"
#include "../../include/npcs.h"
#include "../../include/language.h"
#include "../../include/char_to_tile.h"
#include "../../include/text_positions.h"
#include "../../assets/chars/chars.h"

static void clean_inventory_name()
{
    uint8_t empty = 255;
    for (uint8_t i = 0; i < 10; i++)
    {
        set_bkg_tile_xy(INVENTORY_ITEM_START_X + i, INVENTORY_ITEM_START_Y, empty);
    }
}

void InventoryScene_Update(Scene *scene)
{
    InventoryScene_CheckInput();
    draw_actor(option_actor);

    if (selected_item_index != last_selected_item_index)
    {
        last_selected_item_index = selected_item_index;
        clean_inventory_name();

        if (language == ENGLISH)
            for (uint8_t i = 0; inventory[selected_item_index].name_en[i] != '\0'; i++)
            {
                uint8_t txt_tile = char_to_tile(inventory[selected_item_index].name_en[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(INVENTORY_ITEM_START_X + i, INVENTORY_ITEM_START_Y, txt_tile);
            }

        else
            for (uint8_t i = 0; inventory[selected_item_index].name_es[i] != '\0'; i++)
            {
                uint8_t txt_tile = char_to_tile(inventory[selected_item_index].name_es[i]) + CHARS_TILESET_START;
                set_bkg_tile_xy(INVENTORY_ITEM_START_X + i, INVENTORY_ITEM_START_Y, txt_tile);
            }
    }
}