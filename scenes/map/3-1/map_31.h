#ifndef _MAP_31_
#define _MAP_31_

#include "../../../include/entity.h"
#include "../../../include/scene.h"

void Map_31_Init(Scene *scene, Entity scene_player);
void Map_31_Update(Scene *scene);
void Map_31_InitNPCs(void);

extern Scene Map_31;
extern uint8_t book_delivered;

void Map_31_Create(void);
void Map_31_InitDialogues(void);
void Map_31_CheckInput(void);

#endif //_MAP_31_