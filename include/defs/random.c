#include "../random.h"

unsigned int seed = 0;

unsigned int my_rand()
{
    seed = seed * 25173 + 13849;
    return seed;
}