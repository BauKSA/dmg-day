#ifndef _MG_MISSIONCOMPLETE_
#define _MG_MISSIONCOMPLETE_

#include <stdint.h>

#define CSCREEN_TIMER 5

void Mg_SplashCompleteScreen(uint8_t npc_map, uint8_t success, uint16_t reward);
void Mg_CompleteScreenSleep(void);

#endif
