#pragma bank 4

#include "map_31.h"

#include "../2-0/map_20.h"

#include "../../../assets/sprites/NPCs/flag/spr_flag.h"
#include "../../../assets/sprites/NPCs/chica_libro/spr_ChicaLibro.h"
#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/draw.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../map_data.h"

void Map_31_InitNPCs()
{
    position.x[npc_1] = 40;
    position.y[npc_1] = 40;

    char npc_name[10] = "flag";
    for (uint8_t i = 0; i < npc_name[i] != '\0'; i++)
        names[npc_1][i] = npc_name[i];

    position.fixed_x[npc_1] = position.x[npc_1] << 8;
    position.fixed_x[npc_1] = position.y[npc_1] << 8;

    render.tile_start[npc_1] = 0;
    render.tile_count[npc_1] = 4;
    render.vertical[npc_1] = TRUE;

    const unsigned char *npc_sprite[] =
        {
            // primer frame
            spr_Flag00, spr_Flag01,
            spr_Flag02, spr_Flag03,

            // segundo frame
            spr_Flag10,
            spr_Flag11,
            spr_Flag12, spr_Flag13};

    init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 2,
                   DEFAULT_ANIMATION_SPEED * 2, 4);

    CurrentMapData.npc_count = 1;
    CurrentMapData.npc[0] = npc_1;

    draw_actor(npc_1);

    if (purchased_book != NONE_BOOK)
    {
        position.x[npc_2] = 48;
        position.y[npc_2] = 96;

        char npc_name[10] = "c. libro";
        for (uint8_t i = 0; i < npc_name[i] != '\0'; i++)
            names[npc_2][i] = npc_name[i];

        position.fixed_x[npc_2] = position.x[npc_2] << 8;
        position.fixed_x[npc_2] = position.y[npc_2] << 8;

        render.tile_start[npc_2] = 0;
        render.tile_count[npc_2] = 4;
        render.vertical[npc_2] = TRUE;

        const unsigned char *npc_2_sprite[] =
            {// primer frame
             spr_ChicaLibro00,
             spr_ChicaLibro01,
             spr_ChicaLibro02,
             spr_ChicaLibro03};

        init_animation(npc_2, &animation[npc_2], 0, npc_2_sprite, 1,
                       DEFAULT_ANIMATION_SPEED, 4);

        uint8_t empty_tile = 255;
        set_bkg_tile_xy(5, 10, empty_tile);
        set_bkg_tile_xy(6, 10, empty_tile);
        set_bkg_tile_xy(5, 11, empty_tile);
        set_bkg_tile_xy(6, 11, empty_tile);

        CurrentMapData.npc_count = 2;
        CurrentMapData.npc[1] = npc_2;

        draw_actor(npc_2);
    }
}