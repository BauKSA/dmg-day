#include "./game.h"
#include "./entity.h"

#ifndef SCENE_H
#define SCENE_H

typedef struct Scene Scene;

struct Scene
{
    void (*init)(struct Scene *, Entity player);
    void (*update)(struct Scene *);
    void (*destroy)(struct Scene *);
    void *data;
};

void Scene_Destroy(Scene *scene);

#endif // SCENE_H