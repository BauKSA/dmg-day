#include "./game.h"
#include "./entity.h"

#ifndef SCENE_H
#define SCENE_H

extern Entity npc_1;
extern Entity npc_2;
extern Entity option_actor;

typedef struct Scene Scene;

struct Scene
{
    void (*init)(struct Scene *, Entity player);
    void (*update)(struct Scene *);
    void (*destroy)(struct Scene *);
    void *data;
};

void init_NPCs();
void Scene_Destroy(Scene *scene);

#endif // SCENE_H