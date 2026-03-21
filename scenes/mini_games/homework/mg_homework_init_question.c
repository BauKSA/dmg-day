#pragma bank 6

#include "mg_homework.h"

Mg_Homework_Test test[QUESTION_COUNT] = {
    {
        .question = { .lines_txt = {"who is the", "author of", "the eternauta"}, .lines_count = 3 },
        .options = {
            {"h. g. o.", 1, MGH_UP},
            {"quinterno", 0, MGH_LEFT},
            {"g. ferre", 0, MGH_RIGHT},
            {"altuna", 0, MGH_DOWN}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"what is the", "indep. day", "of argentina"}, .lines_count = 3 },
        .options = {
            {"july 9th", 1, MGH_UP},
            {"july 4th", 0, MGH_LEFT},
            {"june 20th", 0, MGH_RIGHT},
            {"may 25th", 0, MGH_DOWN}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"which arg.", "team was", "never", "relegated"}, .lines_count = 4 },
        .options = {
            {"river", 0, MGH_UP},
            {"indep.", 0, MGH_LEFT},
            {"casla", 0, MGH_RIGHT},
            {"boca", 1, MGH_DOWN}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"game boy is", "out today. in", "what year", "are we"}, .lines_count = 4 },
        .options = {
            {"1979", 0, MGH_UP},
            {"1989", 1, MGH_LEFT},
            {"1990", 0, MGH_RIGHT},
            {"1980", 0, MGH_DOWN}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"where is the", "now defunct", "prison of the", "end of world"}, .lines_count = 4 },
        .options = {
            {"bs as", 0, MGH_UP},
            {"rosario", 0, MGH_LEFT},
            {"ushuaia", 1, MGH_RIGHT},
            {"madryn", 0, MGH_DOWN}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"in which race", "traverso won", "with his car", "on fire"}, .lines_count = 4 },
        .options = {
            {"gral roca", 1, MGH_UP},
            {"pigue", 0, MGH_LEFT},
            {"s. lorenzo", 0, MGH_RIGHT},
            {"bs as", 0, MGH_DOWN}
        },
        .options_count = 4
    }
};