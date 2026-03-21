#ifndef _GAME_OVER_
#define _GAME_OVER_

#include "../../include/game.h"
#include "../../include/entity.h"

void GameOver_Init(Scene* scene, Entity player);
void GameOver_Update(Scene* scene);

extern Scene GameOver;
void GameOver_Create(void);

#endif