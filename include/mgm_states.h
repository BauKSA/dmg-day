#ifndef _MGMSTATES_
#define _MGMSTATES_

enum MGM_STATE
{
    MGM_INACTIVE,
    MGM_ACTIVE
};

typedef struct AllMGMStates
{
    enum MGM_STATE mg_leaves : 1;
    enum MGM_STATE mg_homework : 1;
    enum MGM_STATE mg_final : 1;
    enum MGM_STATE glasses : 1;
    enum MGM_STATE pigeon : 1;
    enum MGM_STATE super : 1;
    enum MGM_STATE book : 1;
} AllMGMStates;

extern AllMGMStates MGM_states;

void init_mgm_states(void);

#endif