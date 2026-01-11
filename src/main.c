#include<gb/gb.h>
#include<stdio.h>

#include "../include/draw.h"
#include "../include/action.h"
#include "../include/player.h"

void main() {
    DISPLAY_ON;
    SHOW_SPRITES;

    const uint8_t player_id = init_player();

    while(1) {
        check_input();
        
        update_animation(&animation[player_id]);
        draw_actor(player_id);

        wait_vbl_done();
    }
}