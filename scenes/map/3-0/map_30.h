#ifndef _MAP_30_
#define _MAP_30_

#include "../../../include/entity.h"
#include "../../../include/scene.h"

void Map_30_Init(Scene *scene, Entity scene_player);
void Map_30_Update(Scene *scene);
void Map_30_Destroy(Scene *scene);

extern Scene Map_30;
extern uint8_t tmp_relation;
extern uint8_t mg_ended;

void Map_30_Create(void);
void Map_30_InitNPC(void);
void Map_30_InitDialogues(void);
void Map_30_CheckInput(void);

#endif //_MAP_30_