#pragma bank 6

#include <stdint.h>

#include "mg_homework.h"

#include "../../../include/intermitent_text.h"

void Mg_Homework_Update(Scene *scene)
{
    uint8_t questions_left = 6;

    // while (questions_left > 0)
    //{
    uint8_t qi = QUESTION_COUNT - questions_left;
    for (uint8_t i = 0; i < test[qi].question.lines_count; i++)
    {
        IntermitentText_Init(4, 4 + i, test[qi].question.lines_txt[i], 15);
    }

    while (1)
        ;
    //}
}