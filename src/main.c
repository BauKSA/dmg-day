#include<gb/gb.h>
#include<stdio.h>

#include "../include/game.h"
#include "../include/scene.h"

/* Include scene headers */
#include "../scenes/gender_select/gender_select.h"
#include "../scenes/map/00/map_00.h"

#include "../include/draw.h"
#include "../include/action.h"
#include "../include/player.h"

void main(void) {
    DISPLAY_ON;
    SHOW_SPRITES;

    Game game;
    game.running = 1;

    init_player();

    Map_00_Create();

    game.current_scene = &Map_00;

    game.current_scene->init(game.current_scene, &player);

    SHOW_BKG;

    while(game.running) {
        game.current_scene->update(game.current_scene);
        
        wait_vbl_done();
    }
}