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
    case 2:
        Mg_Final_Kirby();
        break;
    case 3:
        Mg_Final_Metroid();
        break;
    case 4:
        Mg_Final_Zelda();
        break;
    default:
        break;
    }
}