#ifndef _MGMSTATES_
#define _MGMSTATES_

typedef enum MGM_STATE = {
    MGM_INACTIVE,
    MGM_ACTIVE
} MGM_STATE;

typedef struct AllMGMStates = {
    MGM_STATE mg_leaves;
    MGM_STATE mg_homework;
    MGM_STATE mg_football;
    MGM_STATE glasses;
    MGM_STATE pigeon;
    MGM_STATE super;
    MGM_STATE book;
} AllMGMStates;

extern AllMGMStates MGM_states;

void init_mgm_states(void);

#endif