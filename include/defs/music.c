#include <gb/gb.h>

#include "../music.h"

void MiniGameWin()
{
    // Nota 1 (Do)
    NR10_REG = 0x00;
    NR11_REG = 0x80;
    NR12_REG = 0xF2;
    NR13_REG = 0x2C;
    NR14_REG = 0x84;
    delay(200);

    // Nota 2 (Mi)
    NR13_REG = 0x5D;
    NR14_REG = 0x85;
    delay(200);

    // Nota 3 (Sol)
    NR12_REG = 0xF4;
    NR13_REG = 0x94;
    NR14_REG = 0x86;
}

void MiniGameLose()
{
    // Nota 1
    NR10_REG = 0x00;
    NR11_REG = 0x40;
    NR12_REG = 0xC3;
    NR13_REG = 0x73;
    NR14_REG = 0x86;
    delay(400);

    // Nota 2
    NR13_REG = 0x50;
    NR14_REG = 0x86;
    delay(400);

    // Nota 3
    NR12_REG = 0xC7;
    NR13_REG = 0x00;
    NR14_REG = 0x85;
}