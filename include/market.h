#ifndef _MARKET_
#define _MARKET_
#include <stdint.h>

#define ITEMS_TO_BUY 5

typedef enum MarketItem
{
  EMPTY_ITEM,
  BREAD,
  MILK,
  CANDIES,
  TEA,
  COFFE,
  BATTERIES,
  JAM,
  SOAP,
  COOKIES,
  SODA
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

#endif
