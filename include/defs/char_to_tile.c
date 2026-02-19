#include "../char_to_tile.h"

int char_to_tile(char c) {
    char map[] = "abcdefghijklmnopqrstuvwxyz.,!?'";
    for (int i = 0; i < 32; i++) {
        if (map[i] == c) {
            return i + 1;
        }
    }

    return 0;
}