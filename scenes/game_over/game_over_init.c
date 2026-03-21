#pragma bank 7

#include <gb/gb.h>

#include "../../include/scene.h"

#include "game_over.h"

#include "../../assets/sprites/backgrounds/game_over/bkg_game_over.h"

void GameOver_Init(Scene *scene, Entity player)
{
    set_bkg_data(0, bkg_gameover_tileset_size, bkg_gameover_tileset);
    set_bkg_tiles(0, 0, 20, 18, bkg_gameover_tilemap);
}