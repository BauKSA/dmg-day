#pragma bank 5

#include "../../include/player.h"
#include "../../include/position.h"
#include "../../include/scene.h"
#include "../../include/animation.h"
#include "../../include/render.h"
#include "../../include/draw.h"
#include "../../include/inventory.h"
#include "../../include/npcs.h"
#include "../../include/language.h"
#include "../../include/char_to_tile.h"
#include "../../include/text_positions.h"

#include "../../assets/chars/items.h"

#include "./inventory_scene.h"

#include "../../assets/sprites/backgrounds/inventory/inventory_bkg.h"
#include "../../assets/chars/chars.h"

#include <gb/gb.h>

void InventoryScene_Init(Scene *scene, Entity scene_player)
{
    scene->data = NULL;

    set_bkg_data(0, inventory_bkg_tileset_size, inventory_bkg_tileset);
    set_bkg_tiles(0, 0, 20, 18, inventory_bkg_tilemap);

    InventoryScene_InitArrow();

    selected_item_index = 0;
    last_selected_item_index = 0;

    if (language == SPANISH)
    {
        char txt[] = "inventario";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }
    }
    else
    {
        char txt[] = "inventory";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }
    }

    for (uint8_t i = 0; i < MAX_ITEMS; i++)
    {
        if (inventory[i].item == ITM_NONE)
            continue;

        uint8_t tile = ITEMS_TILESET_START + (uint8_t)inventory[i].item;
        uint8_t y = 9;
        uint8_t x = 0;

        if (i == 0)
            x = 5;
        else if (i == 1)
            x = 8;
        else if (i == 2)
            x = 11;
        else
            x = 14;

        set_bkg_tile_xy(x, y, tile);
    }

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

    InventoryScene_DrawCoins();
}