#ifndef _MG_LOADSCREEN_
#define _MG_LOADSCREEN_
#include <stdint.h>

extern uint8_t mgl_current_frame;
extern uint8_t mgl_target_frame;
extern uint8_t mgl_active;
extern uint8_t mgl_initialized;

void Mg_LoadScreenInit(void);
void Mg_LoadScreenUpdate(void);

#endif
