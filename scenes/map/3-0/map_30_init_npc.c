#pragma bank 4

#include "map_30.h"

#include "../../../assets/sprites/NPCs/vieja_escoba/spr_ViejaEscoba.h"
#include "../../../include/animation.h"
#include "../../../include/name.h"
#include "../../../include/npcs.h"
#include "../../../include/position.h"
#include "../../../include/render.h"
#include "../map_data.h"

void Map_30_InitNPC()
{
  position.x[npc_1] = 56;
  position.y[npc_1] = 112;

  char npc_name[10] = "vieja";
  uint8_t i = 0;
  for (i = 0; i < npc_name[i] != '\0'; i++)
    names[npc_1][i] = npc_name[i];

  names[npc_1][i] = '\0';

  position.fixed_x[npc_1] = position.x[npc_1] << 8;
  position.fixed_x[npc_1] = position.y[npc_1] << 8;

  render.tile_start[npc_1] = 0;
  render.tile_count[npc_1] = 4;
  render.vertical[npc_1] = TRUE;

  const unsigned char *npc_sprite[] = {
      // primer frame
      spr_ViejaEscoba00,
      spr_ViejaEscoba01,
      spr_ViejaEscoba02,
      spr_ViejaEscoba03,
      // segundo frame
      spr_ViejaEscoba10,
      spr_ViejaEscoba11,
      spr_ViejaEscoba12,
      spr_ViejaEscoba13,
  };

  init_animation(npc_1, &animation[npc_1], 0, npc_sprite, 2,
                 DEFAULT_ANIMATION_SPEED * 2, 4);
}
