#include<gb/gb.h>
#include<stdio.h>

#include "../include/game.h"
#include "../include/scene.h"

/* Include scene headers */
#include "../scenes/gender_select/gender_select.h"

#include "../include/draw.h"
#include "../include/action.h"
#include "../include/player.h"

void main(void) {
    DISPLAY_ON;
    SHOW_SPRITES;

    Game game;
    game.running = 1;

    GenderSelect_Create();

    game.current_scene = &GenderSelect;

    game.current_scene->init(game.current_scene);

    const uint8_t player_id = init_player();

    SHOW_BKG;

    while(game.running) {
        //check_input();
        wait_vbl_done();
    }
}