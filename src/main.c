#include <gb/gb.h>
#include <stdio.h>

#include "../include/game.h"
#include "../include/scene.h"

/* Include scene headers */
#include "../scenes/gender_select/gender_select.h"

#include "../include/draw.h"
#include "../include/action.h"
#include "../include/player.h"
#include "../include/gender_selection.h"
#include "../include/scene_manager.h"

void main(void)
{
    DISPLAY_ON;
    SHOW_SPRITES;

    /*
    Game game; se guarda en el stack. El stack de la GB es muy chico, así que
    muchas veces se sobreescribe y puede llegar a corromper la variable, por eso
    algo que persiste como el game, debería ser static.
    */
   
    static Game game;
    game.running = 1;

    init_player();

    enum GenderSelect gender = &GENDER;
    SceneManager_Create(&game);

    scene_manager->change_scene(GENDER_SELECT, player);

    while (game.running)
    {
        game.current_scene->update(game.current_scene);

        wait_vbl_done();
    }
}