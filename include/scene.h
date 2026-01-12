#include "./game.h"

#ifndef SCENE_H
#define SCENE_H

struct Scene {
    void (*init)(Scene*);      // Init
    // void (*update)(Scene*);    // Update
    // void (*render)(Scene*);    // Draw
    // void (*destroy)(Scene*);   // Clean
    void* data;
};

#endif // SCENE_H