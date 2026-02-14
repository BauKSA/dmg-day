#include <stddef.h>
#include <stdlib.h>

#include "../scene.h"

Entity npc_1;
Entity npc_2;
Entity option_actor;

void init_NPCs(){
    npc_1 = create_entity();
    npc_2 = create_entity();
    option_actor = create_entity();
}

void Scene_Destroy(Scene *scene)
{
    if (!scene->data)
        return;

    free(scene->data);
    scene->data = NULL;
}