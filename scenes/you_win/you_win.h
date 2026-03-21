#ifndef _YOU_WIN_
#define _YOU_WIN_

#include "../../include/game.h"
#include "../../include/entity.h"

void YouWin_Init(Scene* scene, Entity player);
void YouWin_Update(Scene* scene);

extern Scene YouWin;
void YouWin_Create(void);

#endif