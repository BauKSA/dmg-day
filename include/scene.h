#include "./game.h"
#include "./entity.h"

#ifndef SCENE_H
#define SCENE_H

struct Scene {
    void (*init)(Scene*, Entity player);      // Init
    void (*update)(Scene*);    // Update
    // void (*render)(Scene*);    // Draw
    void (*destroy)(Scene*);   // Clean
    void* data;
};

void Scene_Destroy(Scene* scene);

#endif // SCENE_H