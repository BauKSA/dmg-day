#include "mg_leaves.h"
#include "../../../include/scene.h"
#include "../../../include/minigames.h"

Scene Mg_Leaves;

void Mg_Leaves_Create(void)
{
    Mg_Leaves.init = Mg_Leaves_Init;
    Mg_Leaves.update = Mg_Leaves_Update;
    Mg_Leaves.bank = 2;
    Mg_Leaves.data = NULL;

    minigame_list[LSMG_LEAVES] = 1;
}