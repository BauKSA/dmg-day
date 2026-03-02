#include "./text_frame.h"
#include <gb/gb.h>
#include <stdint.h>

void TextFrame_Init(uint8_t width, uint8_t height) {
  set_bkg_data(TEXT_FRAME_TILESET_START, text_frame_tileset_size,
               text_frame_tileset);

  uint8_t x, y, w, h;
  uint8_t i;
  uint8_t screen_y = 0;

  // --- PARTE 1: Dibujamos las primeras 2 filas (Superiores) ---
  for (y = 0; y < 2; y++) {
    i = y * 5; // Fila 0 o 1 del tilemap

    // Dibujar borde izquierdo (col 0 y 1)
    set_bkg_tile_xy(1 + 0, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);
    set_bkg_tile_xy(1 + 1, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);

    // Centro repetido (col 2)
    uint8_t tile_centro = text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START;
    for (w = 0; w < width; w++) {
      set_bkg_tile_xy(1 + 2 + w, 3 + screen_y, tile_centro);
    }

    // Borde derecho (col 3 y 4)
    set_bkg_tile_xy(1 + 2 + width + 0, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);
    set_bkg_tile_xy(1 + 2 + width + 1, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);

    screen_y++;
  }

  // --- PARTE 2: Repetimos la Fila del Medio (Fila 2 del tilemap) ---
  for (h = 0; h < height; h++) {
    i = 10; // La fila 2 empieza en el tile 10

    set_bkg_tile_xy(1 + 0, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);
    set_bkg_tile_xy(1 + 1, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);

    uint8_t tile_centro_mid =
        text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START;
    for (w = 0; w < width; w++) {
      set_bkg_tile_xy(1 + 2 + w, 3 + screen_y, tile_centro_mid);
    }

    set_bkg_tile_xy(1 + 2 + width + 0, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);
    set_bkg_tile_xy(1 + 2 + width + 1, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);

    screen_y++;
  }

  // --- PARTE 3: Dibujamos las últimas 2 filas (Inferiores) ---
  for (y = 0; y < 2; y++) {
    i = (y + 3) * 5; // Filas 3 y 4 del tilemap

    set_bkg_tile_xy(1 + 0, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);
    set_bkg_tile_xy(1 + 1, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);

    uint8_t tile_centro_bot =
        text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START;
    for (w = 0; w < width; w++) {
      set_bkg_tile_xy(1 + 2 + w, 3 + screen_y, tile_centro_bot);
    }

    set_bkg_tile_xy(1 + 2 + width + 0, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);
    set_bkg_tile_xy(1 + 2 + width + 1, 3 + screen_y,
                    text_frame_tilemap[i++] + TEXT_FRAME_TILESET_START);

    screen_y++;
  }
}
