#include "./story.h"
#include "../../include/scene.h"
#include <stdint.h>

Scene Story;
StoryLine story_lines[6];
uint8_t story_lines_count = 0;
uint8_t story_lines_rate = 7;
uint8_t story_lines_timer = 0;
uint8_t actual_story_line = 0;
uint8_t actual_line_char = 0;
uint8_t ended = 0;

void Story_Create()
{
  Story.init = Story_Init;
  Story.update = Story_Update;
  Story.bank = 7;
}
