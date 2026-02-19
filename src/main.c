#include <gb/gb.h>
#include <stdlib.h>

#include "../include/game.h"
#include "../include/scene.h"

/* Include scene headers */
#include "../scenes/gender_select/gender_select.h"

#include "../include/draw.h"
#include "../include/action.h"
#include "../include/player.h"
#include "../include/gender_selection.h"
#include "../include/scene_manager.h"
#include "../include/scene.h"
#include "../include/npcs.h"
#include "../include/input.h"

#include "../assets/chars/numbers.h"
#include "../assets/chars/chars.h"
#include "../assets/sprites/backgrounds/npc_icons/npc_icons.h"

#include "../include/inventory.h"

// Carga los tiles de números al inicio del juego
void load_number_tiles()
{
    set_bkg_data(CHARS_TILESET_START, chars_tileset_size, (uint8_t *)chars_tileset);
    set_bkg_data(NUMBER_TILESET_START, numbers_tileset_size, (uint8_t *)numbers_tileset);
}

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

    InitNPCIcons();

    init_player();
    init_NPCs();

    enum GenderSelect gender = &GENDER;
    SceneManager_Create(&game);

    scene_manager->change_scene(MENU, player);

    load_number_tiles();

    while (game.running)
    {
        wait_vbl_done();

        prev_keys = keys;
        keys = joypad();

        game.current_scene->update(game.current_scene);
    }
}