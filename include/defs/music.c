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

void MiniGamePassed()
{
    NR10_REG = 0x00;
    NR11_REG = 0x80;
    NR12_REG = 0xF2;
    NR13_REG = 0x2C; // Nota: Do
    NR14_REG = 0x84;
    delay(150);

    NR13_REG = 0x2C;
    NR14_REG = 0x84;
    delay(150);

    NR13_REG = 0x2C;
    NR14_REG = 0x84;
    delay(150);

    NR12_REG = 0xF4;
    NR13_REG = 0x94; // Nota: Do (octava superior)
    NR14_REG = 0x86;
    delay(600);

    // 5. La nota final
    NR10_REG = 0x17;
    NR11_REG = 0x80;
    NR12_REG = 0xF7;
    NR13_REG = 0xD7; // Nota: Mi alto
    NR14_REG = 0x86;

    NR41_REG = 0x01;
    NR42_REG = 0x96;
    NR43_REG = 0x44;
    NR44_REG = 0x80;

    delay(3000);
}

void MiniGameNotPassed()
{
    NR10_REG = 0x00;
    NR11_REG = 0x40;
    NR12_REG = 0xC2;
    NR13_REG = 0x00;
    NR14_REG = 0x85;
    delay(400);

    NR13_REG = 0x50;
    NR14_REG = 0x86;
    delay(400);

    NR10_REG = 0x1E;
    NR13_REG = 0x40;
    NR14_REG = 0x86;
    delay(800);

    NR10_REG = 0x00;
    NR12_REG = 0xC7;
    NR13_REG = 0x10;
    NR14_REG = 0x84;

    NR41_REG = 0x01;
    NR42_REG = 0xA7;
    NR43_REG = 0x67;
    NR44_REG = 0x80;

    delay(3000);
}

void EarnMoney()
{
    NR10_REG = 0x15;
    NR11_REG = 0x81;
    NR12_REG = 0xF3;
    NR13_REG = 0x73;
    NR14_REG = 0x86;
}

void Walk()
{
    NR41_REG = 0x01;
    NR42_REG = 0x11;
    NR43_REG = 0x51;
    NR44_REG = 0x80;
}

void SetDialogue()
{
    NR10_REG = 0x00;
    NR11_REG = 0x81;
    NR12_REG = 0x41;
    NR13_REG = 0x73;
    NR14_REG = 0x85;
}

void AcceptHelp()
{
    NR10_REG = 0x15;
    NR11_REG = 0x81;
    NR12_REG = 0x52;
    NR13_REG = 0x73;
    NR14_REG = 0x85;
}

void DeclineHelp()
{
    NR10_REG = 0x1E;
    NR11_REG = 0x41;
    NR12_REG = 0x62;
    NR13_REG = 0x00;
    NR14_REG = 0x86;
}

void Woof()
{
    NR10_REG = 0x16;
    NR11_REG = 0x41;
    NR12_REG = 0xA2;
    NR13_REG = 0x50;
    NR14_REG = 0x86;
}

void Angru()
{
    NR10_REG = 0x27;
    NR11_REG = 0x82;
    NR12_REG = 0x44;
    NR13_REG = 0x10;
    NR14_REG = 0x86;
}

void Paid()
{
    NR10_REG = 0x1E;
    NR11_REG = 0x41;
    NR12_REG = 0x52;
    NR13_REG = 0x20;
    NR14_REG = 0x86;
}