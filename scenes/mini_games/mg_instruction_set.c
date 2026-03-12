#pragma bank 6

#include "./mg_instruction_set.h"
#include "../../include/char_to_tile.h"
#include "../../assets/chars/chars.h"
#include "../../assets/chars/numbers.h"
#include "../../assets/chars/buttons.h"
#include "../../assets/sprites/backgrounds/template/template.h"
#include "../../include/input.h"
#include "../../include/language.h"

#include <gb/gb.h>

void Mg_InstructionSet(Instruction *instructions, uint8_t instruction_count, Requirement *reqs, uint8_t reqs_count)
{
    set_bkg_data(0, template_tileset_size, template_tileset);
    set_bkg_tiles(0, 0, 20, 18, template_tilemap);

    for (uint8_t i = 0; i < instruction_count; i++)
    {
        uint8_t button_x = 0;
        char *instruction = instructions[i].text;
        for (uint8_t j = 0; j < 15 && instruction[j] != '\0'; j++)
        {
            uint8_t char_tile = char_to_tile(instruction[j]) + CHARS_TILESET_START;
            set_bkg_tile_xy(j + 1, 3 + i, char_tile);
            button_x = j + 3;
        }

        uint8_t button = (uint8_t)instructions[i].button + BUTTON_TILESET_START;
        set_bkg_tile_xy(button_x, 3 + i, button);
    }

    if (language == SPANISH)
    {
        char txt[] = "requisitos";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(1 + i, 7, tile);
        }
    }
    else
    {
        char txt[] = "requirements";
        for (uint8_t i = 0; txt[i] != '\0'; i++)
        {
            uint8_t tile = char_to_tile(txt[i]) + CHARS_TILESET_START;
            set_bkg_tile_xy(1 + i, 7, tile);
        }
    }

    for (uint8_t i = 0; i < reqs_count; i++)
    {
        uint8_t tens = reqs[i].qty / 10;
        uint8_t units = reqs[i].qty % 10;

        uint8_t tens_tile = NUMBER_TILESET_START + tens;
        uint8_t units_tile = NUMBER_TILESET_START + units;

        set_bkg_tile_xy(1, 8 + i, tens_tile);
        set_bkg_tile_xy(2, 8 + i, units_tile);

        for (uint8_t j = 0; reqs[i].text[j] != '\0'; j++)
        {
            uint8_t tile = char_to_tile(reqs[i].text[j]) + CHARS_TILESET_START;
            set_bkg_tile_xy(4 + j, 8 + i, tile);
        }
    }

    uint8_t button = (uint8_t)A + BUTTON_TILESET_START;
    uint8_t empty_tile = 255;

    set_bkg_tile_xy(17, 12, button);

    keys = 0;
    uint8_t frame_counter = 0;
    uint8_t visible = 1;

    while (1)
    {
        frame_counter++;

        if (frame_counter >= 25)
        {
            frame_counter = 0;

            if (visible == 1)
            {
                set_bkg_tile_xy(17, 12, empty_tile);
                visible = 0;
            }
            else
            {
                set_bkg_tile_xy(17, 12, button);
                visible = 1;
            }
        }

        vsync();

        keys = joypad();

        if (keys & J_A)
            break;
    }
}