#include <stdlib.h>
#include <gb/gb.h>

#include "../../../include/game.h"
#include "../../../include/entity.h"
#include "../../../include/npc_lines.h"

#ifndef MG_LEAVES_H
#define MG_LEAVES_H

#define LEAF_COUNT 5
#define GARBAGE_COUNT 3
#define TOTAL_ACTORS (LEAF_COUNT + GARBAGE_COUNT)

void Mg_Leaves_Init(Scene *scene, Entity scene_player);
void Mg_Leaves_Update(Scene *scene);
void Mg_Leaves_Player_Init();

typedef enum ActorState
{
    FALLING,
    ON_FLOOR,
    BEING_SWEPT_RIGHT,
    BEING_SWEPT_LEFT
};

typedef struct MG_Leaves_DATA
{
    uint8_t bottom_limit;
    uint8_t right_limit;
} MG_Leaves_DATA;

extern MG_Leaves_DATA mg_leaves_DATA;

extern Scene Mg_Leaves;
extern uint8_t actor_ids[TOTAL_ACTORS];
extern uint8_t actor_x[TOTAL_ACTORS];
extern uint8_t actor_spawn_x[TOTAL_ACTORS];
extern int8_t actor_y[TOTAL_ACTORS];
extern uint8_t actor_active[TOTAL_ACTORS];
extern uint8_t actor_timer[TOTAL_ACTORS];
extern uint16_t actor_spawner[TOTAL_ACTORS];
extern enum ActorState actor_state[TOTAL_ACTORS];
extern uint8_t SWEEPING_FLAG;

void Mg_Leaves_Create(void);
void Mg_Leaves_LoadBKG();

#endif // MG_LEAVES_H