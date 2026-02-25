#ifndef _MGTIMER_
#define _MGTIMER_
#include <stdint.h>

#define FPS 60

extern uint8_t mgt_current_frame;
extern uint16_t mgt_target_frame;
extern uint8_t mgt_running;
extern uint8_t mgt_alarm;

void Mg_TimerStart(uint16_t target_seconds);
void Mg_TimerUpdate();
void Mg_TimerStopAlarm();

#endif //_MGTIMER_
