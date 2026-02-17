#include <stddef.h>
#include <stdlib.h>
#include <gb/gb.h>

#include "../scene_manager.h"
#include "../player.h"
#include "../scene.h"
#include "../position.h"
#include "../draw.h"
#include "../npcs.h"

SceneManager *scene_manager;

void SceneManager_CleanScreen()
{
    // Limpiar Y entera
    position.y[player] = 0;
    position.y[npc_1] = 0;
    position.y[npc_2] = 0;
    position.y[option_actor] = 0;
}

void SceneManager_Create(Game *game)
{
    scene_manager = (SceneManager *)malloc(sizeof(SceneManager));

    scene_manager->game = game;
    scene_manager->change_scene = SceneManager_ChangeScene;
}

void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player)
{
    if (!scene_manager->game)
        return;

    if (scene_manager->game->current_scene && scene_manager->game->current_scene->destroy)
        scene_manager->game->current_scene->destroy(scene_manager->game->current_scene);

    scene_manager->game->current_scene = scene_manager_MapScene(new_scene);

    SceneManager_CleanScreen();
    scene_manager->game->current_scene->init(scene_manager->game->current_scene, player);

    SHOW_BKG;
}