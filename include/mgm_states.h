#ifndef _MGMSTATES_
#define _MGMSTATES_

enum MGM_STATE {
    MGM_INACTIVE,
    MGM_ACTIVE
};

typedef struct AllMGMStates {
    enum MGM_STATE mg_leaves;
    enum MGM_STATE mg_homework;
    enum MGM_STATE mg_football;
    enum MGM_STATE glasses;
    enum MGM_STATE pigeon;
    enum MGM_STATE super;
    enum MGM_STATE book;
} AllMGMStates;

extern AllMGMStates MGM_states;

void init_mgm_states(void);

#endif