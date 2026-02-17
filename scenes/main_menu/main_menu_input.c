#include <gb/gb.h>
#include "./main_menu.h"
#include "../../include/scene.h"
#include "../../include/scene_manager.h"
#include "../../include/player.h"
#include "../../include/input.h"

void MainMenu_CheckInput(void)
{
    keys = joypad();

    if (!(keys & J_START) && (prev_keys & J_START))
    {
        scene_manager->change_scene(MAP_00, player);
    }

    prev_keys = keys;
}