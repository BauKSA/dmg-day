#include <gb/gb.h>

#include "../inventory.h"
#include "../../assets/chars/items.h"

Slot inventory[MAX_ITEMS];

uint8_t active_item_index = 0;
Item active_item = ITM_NONE;

uint8_t selected_item_index = 0;
uint8_t last_selected_item_index = 0;

void init_inventory()
{
    for (uint8_t i = 0; i < MAX_ITEMS; i++)
        inventory[i].item = ITM_NONE;

    // FOR DEBUG: EMPEZAMOS CON TODOS LOS ITEMS:
    inventory[0].item = BRANCH;
    char branch_name_en[] = "branch";
    char branch_name_es[] = "rama";
    uint8_t index = 0;
    for (uint8_t i = 0; branch_name_en[i] != '\0'; i++)
    {
        inventory[0].name_en[i] = branch_name_en[i];
        index++;
    }
    inventory[0].name_en[index] = '\0';
    index = 0;
    for (uint8_t i = 0; branch_name_es[i] != '\0'; i++)
    {
        inventory[0].name_es[i] = branch_name_es[i];
        index++;
    }
    inventory[0].name_es[index] = '\0';

    inventory[1].item = GLASSES;
    char glassess_name_en[] = "glasses";
    char glassess_name_es[] = "anteojos";
    for (uint8_t i = 0; glassess_name_en[i] != '\0'; i++)
    {
        inventory[1].name_en[i] = glassess_name_en[i];
    }
    for (uint8_t i = 0; glassess_name_es[i] != '\0'; i++)
    {
        inventory[1].name_es[i] = glassess_name_es[i];
    }

    inventory[2].item = BREAD;
    char bread_name_en[] = "bread";
    char bread_name_es[] = "pan";
    for (uint8_t i = 0; bread_name_en[i] != '\0'; i++)
    {
        inventory[2].name_en[i] = bread_name_en[i];
    }
    for (uint8_t i = 0; bread_name_es[i] != '\0'; i++)
    {
        inventory[2].name_es[i] = bread_name_es[i];
    }

    inventory[3].item = BOOK;
    char book_name_en[] = "book";
    char book_name_es[] = "libro";
    for (uint8_t i = 0; book_name_en[i] != '\0'; i++)
    {
        inventory[3].name_en[i] = book_name_en[i];
    }
    for (uint8_t i = 0; book_name_es[i] != '\0'; i++)
    {
        inventory[3].name_es[i] = book_name_es[i];
    }

    set_bkg_data(ITEMS_TILESET_START, items_tileset_size, items_tileset);
}