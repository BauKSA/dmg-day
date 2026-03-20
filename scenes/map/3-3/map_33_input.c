#include <stdint.h>
#pragma bank 5

#include <gb/gb.h>

#include "../../../include/char_to_tile.h"
#include "../../../include/draw.h"
#include "../../../include/input.h"
#include "../../../include/language.h"
#include "../../../include/npc_stats_map.h"
#include "../../../include/npcs.h"
#include "../../../include/player.h"
#include "../../../include/position.h"
#include "../../../include/mgm_states.h"
#include "../../../include/music.h"

#include "../../../assets/chars/buttons.h"
#include "../../../assets/chars/chars.h"
#include "../../../assets/sprites/frames/text_frame.h"

#include "../map_data.h"

#include "map_33.h"

void Map_33_CheckInput()
{
  if (CurrentMapData.event_active == 0)
    return;

  if ((keys & J_A) && !(prev_keys & J_A))
  {
    Scene_DrawNPCLine(npc_1, (uint8_t)NPC_SUPER, 0, 0, NONE);

    if (MGM_states.super == MGM_INACTIVE)
      return;

    if (dialogue_phase[(uint8_t)NPC_SUPER] == 0)
    {
      cache_player_position();
      position.y[player] = 0;
      position.y[npc_1] = 0;

      draw_actor(player);
      draw_actor(npc_1);

      TextFrame_Init(12, 4);

      char *line_a;
      char *line_b;
      char *line_c;

      char *accept;
      char *decline;

      uint8_t a_button = BUTTON_TILESET_START + 1;
      uint8_t b_button = BUTTON_TILESET_START + 2;

      uint8_t a_btn_start;
      uint8_t b_btn_start;

      if (language == SPANISH)
      {
        line_a = "hacer las";
        line_b = "compras del";
        line_c = "super";

        accept = "ayudar";
        decline = "irse";

        a_btn_start = 8;
        b_btn_start = 2;
      }
      else
      {
        line_a = "go to the";
        line_b = "market";
        line_c = "\0";

        accept = "help";
        decline = "ignore";

        a_btn_start = 12;
        b_btn_start = 2;
      }

      for (uint8_t i = 0; line_a[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(line_a[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 4, tile);
      }

      for (uint8_t i = 0; line_b[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(line_b[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(2 + i, 5, tile);
      }

      for (uint8_t i = 0; line_c[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(line_c[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(2 + i, 6, tile);
      }

      set_bkg_tile_xy(a_btn_start, 8, a_button);
      set_bkg_tile_xy(b_btn_start, 8, b_button);

      for (uint8_t i = 0; accept[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(accept[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(a_btn_start + 1 + i, 8, tile);
      }

      for (uint8_t i = 0; decline[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(decline[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(b_btn_start + 1 + i, 8, tile);
      }

      for (uint8_t i = 0; i < 15; i++)
        vsync();

      keys = 0;
      prev_keys = 0;
      uint8_t mission_accepted = 0;

      while (1)
      {
        prev_keys = keys;
        keys = joypad();

        if (!(keys & J_A) && (prev_keys & J_A))
        {
          dialogue_phase[(uint8_t)NPC_SUPER] = 1;
          relation_stats[(int8_t)NPC_SUPER] = 2;
          mission_accepted = 1;

          AcceptHelp();

          break;
        }

        if (!(keys & J_B) && (prev_keys & J_B))
        {
          dialogue_phase[(uint8_t)NPC_SUPER] = 3;
          humor_stats[(uint8_t)NPC_SUPER] = 0;
          relation_stats[(uint8_t)NPC_SUPER] = 0;

          DeclineHelp();

          break;
        }
      }

      TextFrame_Close(12, 5);

      Map_33_InitDialogues();

      clean();
      vsync();

      Scene_DrawNPCLine(npc_1, (uint8_t)NPC_SUPER, 0, 0, NONE);

      if (mission_accepted == 0)
      {
        init_player();
        Map_33_InitNPC();

        return;
      }

      TextFrame_Init(12, 6);
      char *list[5];
      char *title;

      if (language == SPANISH)
      {
        title = "lista";

        list[0] = "*leche";
        list[1] = "*te";
        list[2] = "*mermelada";
        list[3] = "*soda";
        list[4] = "*galletas";
      }
      else
      {
        title = "list";

        list[0] = "*milk";
        list[1] = "*tea";
        list[2] = "*jam";
        list[3] = "*soda";
        list[4] = "*biscuits";
      }

      for (uint8_t i = 0; title[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(title[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(3 + i, 4, tile);
      }

      for (uint8_t i = 0; i < 5; i++)
      {
        for (uint8_t j = 0; list[i][j] != '\0'; j++)
        {
          uint8_t tile = char_to_tile(list[i][j]) + CHARS_TILESET_START;
          set_bkg_tile_xy(2 + j, 6 + i, tile);
        }
      }

      uint8_t empty_tile = 255;
      set_bkg_tile_xy(13, 10, a_button);

      uint8_t timer = 0;
      uint8_t rate = 45;
      uint8_t show = 0;

      keys = 0;
      prev_keys = 0;

      while (1)
      {
        vsync();

        prev_keys = keys;
        keys = joypad();

        if (!(keys & J_A) && (prev_keys & J_A))
        {
          update_33_dialogue = 1;
          break;
        }

        timer++;
        if (timer >= rate)
        {
          timer = 0;

          if (show == 0)
          {
            set_bkg_tile_xy(13, 10, empty_tile);
            show = 1;
          }
          else
          {
            set_bkg_tile_xy(13, 10, a_button);
            show = 0;
          }
        }
      }

      TextFrame_Close(12, 6);

      init_player();
      Map_33_InitNPC();
    }
    else if (dialogue_phase[(uint8_t)NPC_SUPER] == 2)
    {
      TextFrame_Init(12, 2);

      char *accept;
      char *decline;

      if (language == SPANISH)
      {
        accept = "entregar";
        decline = "todavia no";
      }
      else
      {
        accept = "deliver";
        decline = "not yet";
      }

      uint8_t a_button = BUTTON_TILESET_START + 1;
      uint8_t b_button = BUTTON_TILESET_START + 2;

      set_bkg_tile_xy(2, 5, a_button);
      set_bkg_tile_xy(2, 6, b_button);

      for (uint8_t i = 0; accept[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(accept[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(4 + i, 5, tile);
      }

      for (uint8_t i = 0; decline[i] != '\0'; i++)
      {
        uint8_t tile = char_to_tile(decline[i]) + CHARS_TILESET_START;
        set_bkg_tile_xy(4 + i, 6, tile);
      }

      keys = 0;
      prev_keys = 0;

      while (1)
      {
        vsync();

        prev_keys = keys;
        keys = joypad();

        if (!(keys & J_B) && (prev_keys & J_B))
          break;

        if (!(keys & J_A) && (prev_keys & J_A))
        {
          TextFrame_Close(12, 2);
          Map_33_Deliver();

          return;
        }
      }

      TextFrame_Close(12, 2);

      return;
    }
  }
}
