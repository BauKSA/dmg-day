#ifndef _INVENTORY_
#define _INVENTORY_
#include <stdint.h>

#define MAX_ITEMS 4

typedef enum Item
{
    ITM_NONE,

    BRANCH,
    GLASSES,
    BREAD,
    BOOK
} Item;

typedef struct Slot
{
    Item item;
    char name_es[10];
    char name_en[10];
} Slot;

extern Slot inventory[MAX_ITEMS];
extern uint8_t active_item_index;
extern uint8_t active_item;

extern uint8_t selected_item_index;
extern uint8_t last_selected_item_index;

void init_inventory(void);

#endif