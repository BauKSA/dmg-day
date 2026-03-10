#pragma bank 5

#include "language_select.h"

void LanguageSelect_Create()
{
    LanguageSelect.init = LanguageSelect_Init;
    LanguageSelect.update = LanguageSelect_Update;
    LanguageSelect.bank = 5;

    LanguageSelect.data = NULL;
}