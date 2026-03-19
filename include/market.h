#ifndef _MARKET_
#define _MARKET_

#define ITEMS_TO_BUY 5

typedef enum MarketItem {
  BREAD,
  MILK,
  CANDIES,
  TEA,
  COFFE,
  BATTERIES,
  JAM,
  SOAP,
  COOKIES,
} MarketItem;

extern MarketItem items_to_buy[ITEMS_TO_BUY];

#endif
