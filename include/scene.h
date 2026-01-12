#include "./game.h"
#include "./entity.h"

#ifndef SCENE_H
#define SCENE_H

struct Scene {
    void (*init)(Scene*, Entity* player);      // Init
    void (*update)(Scene*);    // Update
    // void (*render)(Scene*);    // Draw
    // void (*destroy)(Scene*);   // Clean
    void* data;
};

#endif // SCENE_H