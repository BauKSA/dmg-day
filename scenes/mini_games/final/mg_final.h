#include <gb/gb.h>
#include <stdlib.h>

#include "../../../include/entity.h"
#include "../../../include/game.h"
#include "../../../include/npc_lines.h"

#ifndef MG_FINAL_H
#define MG_FINAL_H

#define GAMES 10

void Mg_Final_Init(Scene *scene, Entity scene_player);
void Mg_Final_Update(Scene *scene);

extern Scene Mg_Final;

extern uint8_t wins;
extern const uint8_t win_goal;
extern uint8_t current_game;

void Mg_Final_Create(void);
// void Mgf_clean(void);

// MINI GAMES
void Mg_Final_Tetris(void);
void Mg_Final_Mario(void);

#endif // MG_FINAL_H
