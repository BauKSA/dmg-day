#ifndef _MARKET_
#define _MARKET_
#include <stdint.h>

#define ITEMS_TO_BUY 5

typedef enum MarketItem
{
  MKT_EMPTY,
  MKT_BREAD,
  MKT_MILK,
  MKT_CANDIES,
  MKT_TEA,
  MKT_COFFE,
  MKT_CHOCOLATE,
  MKT_JAM,
  MKT_SOAP,
  MKT_COOKIES,
  MKT_SODA
} MarketItem;

typedef struct MarketItemInfo
{
  MarketItem item;
  uint16_t price;
  char *name_es;
  char *name_en;
} MarketItemInfo;

extern MarketItem items_to_buy[ITEMS_TO_BUY];
extern MarketItem item_cart[10];
extern const MarketItemInfo items_info[10];
extern uint8_t player_items;

#endif
