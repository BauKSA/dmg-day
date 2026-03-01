#include "./mg_load_screen.h"
#include <gb/gb.h>
#include <stdint.h>

#include "../../assets/chars/numbers.h"
#include "../../assets/sprites/backgrounds/template/template.h"

uint8_t mgl_current_frame = 0;
uint8_t mgl_target_frame = 180;
uint8_t mgl_active = 0;
uint8_t mgl_initialized = 0;

void Mg_LoadScreenInit() {
  mgl_current_frame = 0;
  mgl_target_frame = 180;
  mgl_active = 1;
  mgl_initialized = 1;

  unsigned char _previous_bank = _current_bank;
  SWITCH_ROM_MBC1(1);

  set_bkg_data(0, template_tileset_size, template_tileset);
  set_bkg_tiles(0, 0, 20, 18, template_tilemap);

  SWITCH_ROM_MBC1(_previous_bank);
}

void Mg_LoadScreenUpdate() {
  uint8_t tile_cache = 0;
  uint8_t tile = 0;

  while (mgl_active == 1) {
    vsync();

    mgl_current_frame++;
    if (mgl_current_frame >= mgl_target_frame) {
      mgl_active = 0;
      mgl_initialized = 0;
    }

    uint8_t n = 0;
    if (mgl_current_frame <= 60)
      n = 3;
    else if (mgl_current_frame <= 120)
      n = 2;
    else if (mgl_current_frame <= 180)
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
