#include <gb/gb.h>
#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"

#ifndef MG_HOMEWORK_H
#define MG_HOMEWORK_H

#define QUESTION_COUNT 6
#define QUESTION_TIME 5

#define QUESTION_X 4
#define QUESTION_Y 4

#define OPTION_X 8
#define OPTION_Y 9

void Mg_Homework_Init(Scene *scene, Entity scene_player);
void Mg_Homework_Update(Scene *scene);

enum Mg_Homework_BUTTONS { MGH_RIGHT, MGH_LEFT, MGH_UP, MGH_DOWN };

typedef struct Mg_Homework_Answer {
  char txt[10];
  uint8_t correct;
  enum Mg_Homework_BUTTONS button;
} Mg_Homework_Answer;

typedef struct Mg_Homework_Question {
  const char *lines_txt[15];
  uint8_t lines_count;
} Mg_Homework_Question;

typedef struct Mg_Homework_Test {
  Mg_Homework_Question question;
  Mg_Homework_Answer options[4];
  uint8_t options_count;
} Mg_Homework_Test;

extern uint8_t row_tile;
extern Scene Mg_Homework;
extern Mg_Homework_Test test[QUESTION_COUNT];
extern uint8_t correct_answers;
extern const uint8_t correct_goal;

void Mg_Homework_Create(void);
void Mgh_clean(void);

#endif // MG_HOMEWORK_H
