#ifndef _MONEY_
#define _MONEY_
#include<stdint.h>

#define MIN_COIN_VALUE 50
#define MAX_COIN_VALUE 100

#define GAME_BOY_PRICE 1500

extern uint16_t money;

void add_money(uint8_t min_coins_amount, uint8_t max_coins_amount);

#endif //_MONEY_