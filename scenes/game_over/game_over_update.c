#pragma bank 7

#include <gb/gb.h>

#include "../../include/scene.h"
#include "../../include/input.h"
#include "../../include/scene_manager.h"
#include "../../include/all_scenes.h"

#include "game_over.h"

void GameOver_Update(Scene *scene)
{
    if (!(keys & J_START) && (prev_keys & J_START))
        next_scene = MENU;
}