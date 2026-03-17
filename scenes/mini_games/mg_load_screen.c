#pragma bank 6

#include "./mg_load_screen.h"
#include <gb/gb.h>
#include <stdint.h>

#include "../../assets/chars/numbers.h"
#include "../../assets/sprites/backgrounds/template/template_mg.h"

uint8_t mgl_current_frame = 0;
uint8_t mgl_target_frame = 180;
uint8_t mgl_active = 0;
uint8_t mgl_initialized = 0;

void Mg_LoadScreenInit()
{
  mgl_current_frame = 0;
  mgl_target_frame = 120;
  mgl_active = 1;
  mgl_initialized = 1;

  unsigned char _previous_bank = _current_bank;

  set_bkg_data(0, template_mg_tileset_size, template_mg_tileset);
  set_bkg_tiles(0, 0, 20, 18, template_mg_tilemap);
}

void Mg_LoadScreenUpdate()
{
  uint8_t tile_cache = 0;
  uint8_t tile = 0;

  while (mgl_active == 1)
  {
    vsync();

    mgl_current_frame++;
    if (mgl_current_frame >= mgl_target_frame)
    {
      mgl_active = 0;
      mgl_initialized = 0;
    }

    uint8_t n = 0;
    if (mgl_current_frame <= 40)
      n = 3;
    else if (mgl_current_frame <= 80)
      n = 2;
    else if (mgl_current_frame <= 120)
      n = 1;
    else
      n = 0;

    tile = n + NUMBER_TILESET_START;
    if (tile == tile_cache)
      continue;

    tile_cache = tile;

    set_bkg_tile_xy(9, 8, tile);
  }
}
