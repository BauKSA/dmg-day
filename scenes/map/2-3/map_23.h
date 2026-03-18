#ifndef MAP_23_H
#define MAP_23_H

#include "../../../include/entity.h"
#include "../../../include/scene.h"
#include "../2-0/map_20.h"

typedef struct Book
{
    char *line_a;
    char *line_b;
    uint16_t price;
    MissionBooks book;
} Book;

void Map_23_Init(Scene *scene, Entity scene_player);
void Map_23_Update(Scene *scene);

void Map_23_InitNPC(void);
void Map_23_InitDialogues(void);
void Map_23_CheckInput(void);

extern Scene Map_23;
extern uint8_t back;

void Map_23_Create(void);

#endif // !MAP_23_H
