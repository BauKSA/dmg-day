#include <stdlib.h>

#include "../../include/game.h"

#ifndef GENDER_SELECT_H
#define GENDER_SELECT_H

typedef enum
{
    BOY,
    GIRL
} Gender;

typedef struct
{
    Gender gender;
} GenderSelectData;

void GenderSelect_Init(Scene* scene);

extern Scene GenderSelect;
void GenderSelect_Create(void);

#endif // GENDER_SELECT_H