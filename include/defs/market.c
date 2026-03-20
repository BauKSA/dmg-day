#include "../market.h"

MarketItem items_to_buy[ITEMS_TO_BUY] = {
    BREAD,
    TEA,
    JAM,
    COOKIES,
    MILK};

MarketItem item_cart[10] = {EMPTY_ITEM};

const MarketItemInfo items_info[10] = {
    {BREAD, 500, "pan", "bread"},
    {MILK, 400, "leche", "milk"},
    {CANDIES, 150, "caramelos", "candies"},
    {TEA, 150, "te", "tea"},
    {COFFE, 750, "cafe", "coffe"},
    {BATTERIES, 900, "pilas", "batteries"},
    {JAM, 850, "mermelada", "jam"},
    {SOAP, 750, "jabon", "soap"},
    {COOKIES, 650, "galletas", "biscuits"},
    {SODA, 250, "soda", "soda"},
};