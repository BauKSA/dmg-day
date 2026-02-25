#include "./mg_timer.h"

uint8_t mgt_current_frame = 0;
uint16_t mgt_target_frame = 0;
uint8_t mgt_running = 0;
uint8_t mgt_alarm = 0;

void Mg_TimerStart(uint16_t target_seconds) {
  mgt_target_frame = target_seconds * FPS;
  mgt_running = 1;
  mgt_current_frame = 0;
  mgt_alarm = 0;
}

void Mg_TimerUpdate() {
  if (mgt_running == 0)
    return;

  mgt_current_frame++;

  if (mgt_current_frame >= mgt_target_frame) {
    mgt_running = 0;
    mgt_alarm = 1;
  }
}

void Mg_TimerStopAlarm() { mgt_alarm = 0; }
