#pragma bank 6

#include "mg_final.h"

#include "../../../include/scene.h"

void Mg_Final_Update(Scene *scene)
{
    switch (current_game)
    {
    case 0:
        Mg_Final_Tetris();
        break;
    case 1:
        Mg_Final_Mario();
        break;

    default:
        break;
    }
}