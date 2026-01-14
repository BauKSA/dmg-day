#include <stddef.h>
#include <stdlib.h>

#include "../scene.h"

void Scene_Destroy(Scene *scene)
{
    if (!scene->data)
        return;

    free(scene->data);
    scene->data = NULL;
}