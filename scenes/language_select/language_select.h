#ifndef _LANGUAGESELECT_
#define _LANGUAGESELECT_

#include <stdlib.h>

#include "../../include/entity.h"
#include "../../include/game.h"
#include "../../include/scene.h"

#define LANG_ARROW_XA 48
#define LANG_ARROW_XB 120
#define LANG_ARROW_Y 60

void LanguageSelect_Init(Scene *scene, Entity scene_player);
void LanguageSelect_Update(Scene *scene);

extern Scene LanguageSelect;

void LanguageSelect_Create(void);
void LanguageSelect_CheckInput(void);

#endif //_LANGUAGESELECT_
