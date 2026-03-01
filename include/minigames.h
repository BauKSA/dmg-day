#ifndef _MINIGAMES_LIST_
#define _MINIGAMES_LIST_
#include<stdint.h>

typedef enum {
  LSMG_LEAVES,

  LSMG_COUNT
} Minigame;

extern uint8_t minigame_list[LSMG_COUNT];

#endif //_MINIGAMES_LIST_