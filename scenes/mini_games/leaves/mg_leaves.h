#include <stdlib.h>
#include <gb/gb.h>

#include "../../../include/game.h"
#include "../../../include/entity.h"
#include "../../../include/npc_lines.h"

#ifndef MG_LEAVES_H
#define MG_LEAVES_H

#define LEAF_COUNT 5

void Mg_Leaves_Init(Scene *scene, Entity scene_player);
void Mg_Leaves_Update(Scene *scene);
void Mg_Leaves_Player_Init();

typedef enum LeafState
{
    FALLING,
    ON_FLOOR,
    BEING_SWEPT_RIGHT,
    BEING_SWEPT_LEFT
};

typedef struct MG_Leaves_DATA
{
    uint8_t bottom_limit;
} MG_Leaves_DATA;

extern MG_Leaves_DATA mg_leaves_DATA;

extern Scene Mg_Leaves;
extern uint8_t leaf_ids[LEAF_COUNT];
extern uint8_t leaf_x[LEAF_COUNT];
extern int8_t leaf_y[LEAF_COUNT];
extern uint8_t leaf_active[LEAF_COUNT];
extern uint8_t leaf_timer[LEAF_COUNT];
extern uint16_t leaf_spawner[LEAF_COUNT];
extern enum LeafState leaf_state[LEAF_COUNT];
extern uint8_t SWEEPING_FLAG;

void Mg_Leaves_Create(void);
void Mg_Leaves_LoadBKG();

#endif // MG_LEAVES_H