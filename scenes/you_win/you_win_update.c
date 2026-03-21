#pragma bank 7

#include <gb/gb.h>

#include "../../include/scene.h"
#include "../../include/input.h"
#include "../../include/scene_manager.h"
#include "../../include/all_scenes.h"

#include "you_win.h"

void YouWin_Update(Scene *scene)
{
    if (!(keys & J_START) && (prev_keys & J_START))
        next_scene = MENU;
}