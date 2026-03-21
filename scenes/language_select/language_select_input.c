#pragma bank 5

#include "language_select.h"
#include "../../include/input.h"
#include "../../include/language.h"
#include "../../include/position.h"
#include "../../include/npcs.h"
#include "../../include/draw.h"
#include "../../include/player.h"
#include "../../include/scene_manager.h"
#include "../../include/all_scenes.h"
#include "../../include/char_to_tile.h"
#include "../../include/text_positions.h"
#include "../map/map_data.h"

#include "../../assets/chars/chars.h"

#include <gb/gb.h>

void LanguageSelect_CheckInput()
{
    if (!(keys & J_RIGHT) && (prev_keys & J_RIGHT))
    {
        if (language == ENGLISH)
            return;

        clean();

        char txt[] = "language";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }

        position.x[option_actor] = LANG_ARROW_XB;
        position.fixed_x[option_actor] = position.x[option_actor];

        draw_actor(option_actor);

        language = ENGLISH;
    }

    if (!(keys & J_LEFT) && (prev_keys & J_LEFT))
    {
        if (language == SPANISH)
            return;

        clean();

        char txt[] = "idioma";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(NAME_START_X + i, NAME_START_Y, tile);
        }

        position.x[option_actor] = LANG_ARROW_XA;
        position.fixed_x[option_actor] = position.x[option_actor];

        language = SPANISH;

        draw_actor(option_actor);
    }

    if (!(keys & J_A) && (prev_keys & J_A))
        next_scene = STORY;
}