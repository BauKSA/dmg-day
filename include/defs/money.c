#include "../money.h"

uint16_t money = 0;

void add_money(uint8_t min_coins_amount, uint8_t max_coins_amount){
    money += min_coins_amount * MIN_COIN_VALUE;
    money += max_coins_amount * MAX_COIN_VALUE;
}