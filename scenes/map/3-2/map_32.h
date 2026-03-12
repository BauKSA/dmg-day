#ifndef MAP_32_H
#define MAP_32_H

#include "../../../include/entity.h"
#include "../../../include/scene.h"
#include "../../../include/mgm_states.h"

void Map_32_Init(Scene *scene, Entity scene_player);
void Map_32_Update(Scene *scene);
void Map_32_Destroy(Scene *scene);

extern Scene Map_32;
extern enum MGM_STATE mg_32_tmp;
extern uint8_t tmp_relation32;

void Map_32_Create(void);
void Map_32_InitNPC(void);
void Map_32_InitDialogues(void);
void Map_32_CheckInput(void);

#endif // !MAP_32_H
