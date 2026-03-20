#include "../mgm_states.h"

AllMGMStates MGM_states;

void init_mgm_states()
{
    MGM_states.mg_leaves = MGM_ACTIVE;
    MGM_states.mg_final = MGM_ACTIVE;
    MGM_states.mg_homework = MGM_ACTIVE;
    MGM_states.glasses = MGM_ACTIVE;
    MGM_states.book = MGM_ACTIVE;
    MGM_states.super = MGM_ACTIVE;
    MGM_states.pigeon = MGM_ACTIVE;
}