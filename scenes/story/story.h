#ifndef _STORY_
#define _STORY_
#include "../../include/scene.h"
#include <stdint.h>

typedef char StoryLine[12];

void Story_Init(Scene *scene, Entity player);
void Story_Update(Scene *scene);
void Story_Create(void);

extern Scene Story;
extern StoryLine story_lines[6];
extern uint8_t story_lines_count;
extern uint8_t story_lines_rate;
extern uint8_t story_lines_timer;
extern uint8_t actual_story_line;
extern uint8_t actual_line_char;
extern uint8_t ended;

#endif
