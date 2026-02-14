#include "./game.h"
#include "./scene.h"
#include "./all_scenes.h"
#include "./entity.h"

#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

typedef struct SceneManager
{
    Game *game;
    void (*change_scene)(enum AllScenes new_scene, Entity *player);
} SceneManager;

void SceneManager_CleanScreen();
void SceneManager_Create(Game *game);
void SceneManager_ChangeScene(enum AllScenes new_scene, Entity *player);
Scene *scene_manager_MapScene(enum AllScenes scene);

extern SceneManager *scene_manager;

#endif // SCENE_MANAGER_H