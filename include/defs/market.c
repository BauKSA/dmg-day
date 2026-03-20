#include "../market.h"

MarketItem items_to_buy[ITEMS_TO_BUY] = {
    MKT_SODA,
    MKT_TEA,
    MKT_JAM,
    MKT_COOKIES,
    MKT_MILK};

MarketItem item_cart[10] = {MKT_EMPTY};
uint8_t player_items = 0;

const MarketItemInfo items_info[10] = {
    {MKT_BREAD, 500, "pan", "bread"},
    {MKT_MILK, 400, "leche", "milk"},
    {MKT_CANDIES, 150, "caramelos", "candies"},
    {MKT_TEA, 150, "te", "tea"},
    {MKT_COFFE, 750, "cafe", "coffe"},
    {MKT_BATTERIES, 900, "pilas", "batteries"},
    {MKT_JAM, 850, "mermelada", "jam"},
    {MKT_SOAP, 750, "jabon", "soap"},
    {MKT_COOKIES, 650, "galletas", "biscuits"},
    {MKT_SODA, 250, "soda", "soda"},
};