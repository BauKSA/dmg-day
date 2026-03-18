#include "../char_to_tile.h"

int char_to_tile(char c)
{
    char map[] = "abcdefghijklmnopqrstuvwxyz.,!?'*$";
    char number_map[] = "0123456789";

    for (int i = 0; i < 34; i++)
    {
        if (map[i] == c)
        {
            return i + 1;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (number_map[i] == c)
        {
            return i + 34;
        }
    }

    return 0;
}