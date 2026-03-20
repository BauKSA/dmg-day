#ifndef _MAP_33_
#define _MAP_33_

#include "../../../include/entity.h"
#include "../../../include/scene.h"

void Map_33_Init(Scene *scene, Entity scene_player);
void Map_33_Update(Scene *scene);
void Map_33_Destroy(Scene *scene);

extern Scene Map_33;
extern uint8_t update_33_dialogue;

void Map_33_Create(void);
void Map_33_InitNPC(void);
void Map_33_LoadBKG(void);
void Map_33_InitDialogues(void);
void Map_33_CheckInput(void);
void Map_33_Deliver(void);

#endif // _MAP_33_
