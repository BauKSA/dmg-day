#include <gb/gb.h>
#include "./main_menu.h"
#include "../../include/scene.h"
#include "../../include/scene_manager.h"
#include "../../include/player.h"
#include "../../include/input.h"
#include "../../include/npcs.h"

void MainMenu_CheckInput(void)
{
    keys = joypad();

    if (!(keys & J_START) && (prev_keys & J_START))
    {
        seed = LY_REG;
        seed |= (unsigned int)DIV_REG << 8;

        for (size_t i = 0; i < MAX_NPCS; i++)
        {
            humor_stats[i] = my_rand() % 3;
        }

        scene_manager->change_scene(MAP_00, player);
    }

    prev_keys = keys;
}