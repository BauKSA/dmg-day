#include <gb/gb.h>
#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"

#ifndef MG_HOMEWORK_H
#define MG_HOMEWORK_H

#define QUESTION_COUNT 6
#define QUESTION_TIME 5

void Mg_Homework_Init(Scene *scene, Entity scene_player);
void Mg_Homework_Update(Scene *scene);

enum Mg_Homework_BUTTONS{
    MGH_RIGHT,
    MGH_LEFT,
    MGH_UP,
    MGH_DOWN
};

typedef struct Mg_Homework_Answer{
    char txt[8];
    uint8_t correct;
    enum Mg_Homework_BUTTONS button;
}Mg_Homework_Answer;

typedef struct Mg_Homework_Question{
    char *question[15];
    Mg_Homework_Answer[4] options;
    uint8_t options_count;
}Mg_Homework_Question;

extern Scene Mg_Homework;
extern Mg_Homework_Question questions[QUESTION_COUNT];

void Mg_Homework_Create(void);

#endif // MG_HOMEWORK_H