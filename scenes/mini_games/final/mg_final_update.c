#pragma bank 6

#include "mg_final.h"

#include "../../../include/scene.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/scene_manager.h"
#include "../../../include/all_scenes.h"
#include "../../../include/npcs.h"
#include "../mini_games.h"
#include "../mg_mission_complete.h"

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

    if (current_game == 5)
    {
        uint8_t success = 0;
        if (wins >= win_goal)
            success == 1;

        Mg_SplashCompleteScreen((uint8_t)NPC_TIENDA, success, 0);

        if(success){
            humor_stats[(uint8_t)NPC_TIENDA] = 1;
            relation_stats[(uint8_t)NPC_TIENDA] = 0;
        }else{
            humor_stats[(uint8_t)NPC_TIENDA] = 2;
            relation_stats[(uint8_t)NPC_TIENDA] = 2;
        }

        dialogue_phase[(uint8_t)NPC_TIENDA] = 1;

        next_scene = MAP_00;
    }
}