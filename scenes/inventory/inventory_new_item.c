#include <gb/gb.h>
#include <stdint.h>

#include "inventory_scene.h"

#include "../../include/input.h"
#include "../../include/text_positions.h"
#include "../../include/intermitent_text.h"
#include "../../include/char_to_tile.h"
#include "../../include/inventory.h"
#include "../../include/language.h"

#include "../../assets/sprites/backgrounds/template/template.h"
#include "../../assets/chars/items.h"
#include "../../assets/chars/chars.h"
#include "../../assets/chars/buttons.h"

static void SetItemName(Item item, uint8_t inventory_index)
{
    char *name_es;
    char *name_en;

    switch (item)
    {
    case BRANCH:
        name_en = "branch";
        name_es = "ramita";
        break;
    case GLASSES:
        name_en = "glasses";
        name_es = "anteojos";
        break;
    case BREAD:
        name_en = "bread";
        name_es = "pan";
        break;
    case BOOK:
        name_en = "book";
        name_es = "libro";
        break;
    }

    uint8_t i = 0;

    for (i = 0; name_en[i] != '\0'; i++)
        inventory[inventory_index].name_en[i] = name_en[i];

    inventory[inventory_index].name_en[i] = '\0';

    for (i = 0; name_es[i] != '\0'; i++)
        inventory[inventory_index].name_es[i] = name_es[i];

    inventory[inventory_index].name_es[i] = '\0';
}

void NewItemScreen(Item item)
{
    uint8_t _prev_bank = _current_bank;
    vsync();
    SWITCH_ROM_MBC1(5);
    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);
    vsync();
    SWITCH_ROM_MBC1(_prev_bank);

    if (language == SPANISH)
    {
        char name[] = "nuevo item!";
        for (uint8_t i = 0; name[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(name[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }
    }
    else
    {
        char name[] = "new item!";
        for (uint8_t i = 0; name[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(name[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }
    }

    uint8_t index = 0;

    for (uint8_t i = 0; i < MAX_ITEMS; i++)
    {
        if (inventory[i].item == ITM_NONE)
        {
            inventory[i].item = item;
            SetItemName(item, i);
            index = i;

            break;
        }
    }

    uint8_t center_tile_start;

    if (language == SPANISH)
    {
        uint8_t size = 0;
        for (uint8_t i = 0; inventory[index].name_es[i] != '\0'; i++)
            size++;

        center_tile_start = (18 - size) / 2;
        center_tile_start++;
        IntermitentText_Init(center_tile_start, 8, inventory[index].name_es, 10);
    }
    else
    {
        uint8_t size = 1;
        for (uint8_t i = 0; inventory[index].name_en[i] != '\0'; i++)
            size++;

        center_tile_start = (18 - size) / 2;
        center_tile_start++;
        IntermitentText_Init(center_tile_start, 8, inventory[index].name_en, 10);
    }

    uint8_t button = 1 + BUTTON_TILESET_START;
    uint8_t empty_tile = 255;

    set_bkg_data(ITEMS_TILESET_START, items_tileset_size, items_tileset);

    uint8_t icon = (uint8_t)item + ITEMS_TILESET_START;

    set_bkg_tile_xy(center_tile_start, 10, icon);
    set_bkg_tile_xy(11, 10, button);

    keys = 0;
    uint8_t frame_counter = 0;
    uint8_t visible = 1;

    while (1)
    {
        frame_counter++;

        if (frame_counter >= 25)
        {
            frame_counter = 0;

            if (visible == 1)
            {
                set_bkg_tile_xy(11, 10, empty_tile);
                visible = 0;
            }
            else
            {
                set_bkg_tile_xy(11, 10, button);
                visible = 1;
            }
        }

        vsync();

        prev_keys = keys;
        keys = joypad();

        if ((keys & J_A) && !(prev_keys & J_A))
            break;
    }

    return;
}