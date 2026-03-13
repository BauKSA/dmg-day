#pragma bank 6

#include "mg_homework.h"

Mg_Homework_Test test[QUESTION_COUNT] = {
    {
        .question = { .lines_txt = {"pregunta a", "segunda linea"}, .lines_count = 2 },
        .options = {
            {"incorrecta", 0, MGH_RIGHT},
            {"correcta", 1, MGH_LEFT}
        },
        .options_count = 2
    },
    {
        .question = { .lines_txt = {"pregunta b"}, .lines_count = 1 },
        .options = {
            {"mmm, no", 0, MGH_RIGHT},
            {"mmm, si", 1, MGH_LEFT}
        },
        .options_count = 2
    },
    {
        .question = { .lines_txt = {"pregunta c", "linea dos", "una mas"}, .lines_count = 3 },
        .options = {
            {"no", 0, MGH_RIGHT},
            {"no", 0, MGH_LEFT},
            {"si", 1, MGH_UP},
            {"no", 0, MGH_DOWN}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"pregunta d", "linea dos", "una mas", "ultima"}, .lines_count = 4 },
        .options = {
            {"probamos", 0, MGH_RIGHT},
            {"la", 0, MGH_LEFT},
            {"respuesta", 0, MGH_LEFT},
            {"correcta", 1, MGH_LEFT}
        },
        .options_count = 4
    },
    {
        .question = { .lines_txt = {"pregunta e"}, .lines_count = 1 },
        .options = {
            {"solo una", 1, MGH_RIGHT}
        },
        .options_count = 1
    },
    {
        .question = { .lines_txt = {"pregunta f", "esta tiene", "muchas", "muchas", "lineas"}, .lines_count = 5 },
        .options = {
            {"y una respuesta", 0, MGH_RIGHT}
        },
        .options_count = 1
    }
};