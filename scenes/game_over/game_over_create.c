#pragma bank 7

#include "../../include/scene.h"

#include "game_over.h"

void GameOver_Create(void)
{
    GameOver.init = GameOver_Init;
    GameOver.update = GameOver_Update;
    GameOver.bank = 7;
}