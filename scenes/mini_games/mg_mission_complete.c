#include "./mg_mission_complete.h"
#include "../../assets/chars/chars.h"
#include "../../assets/chars/numbers.h"
#include "../../assets/sprites/backgrounds/template/template.h"
#include "../../include/char_to_tile.h"

#include <gb/gb.h>
#include <stdint.h>

void Mg_SplashCompleteScreen() {
  unsigned char _prev_bank = _current_bank;
  SWITCH_ROM_MBC1(1);

  set_bkg_data(0, template_tileset_size, template_tileset);
  set_bkg_tiles(0, 0, 20, 18, template_tilemap);

  SWITCH_ROM_MBC1(_prev_bank);

  char text[16] = "mission complete";
  for (uint8_t i = 0; i < 16; i++) {
    uint8_t tile = char_to_tile(text[i]) + CHARS_TILESET_START;
    set_bkg_tile_xy(2 + i, 8, tile);
  }

  // TO-DO:
  // Acá habría que agregar el icono del botón para continuar

  return;
}

void Mg_CompleteScreenSleep() {
  while (!joypad())
    ;

  return;
}
