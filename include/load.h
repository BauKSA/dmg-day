#pragma once

#ifndef LOAD_H
#define LOAD_H

#include <stdint.h>
#include <gb/gb.h>

#include "entity.h"
#include "render.h"

extern uint8_t vram_next_index; // siguiente slot libre en VRAM
extern uint8_t vram_extra_start;

/**
 * @param e      Entity que recibe los tiles
 * @param tiles  Array de punteros a tiles (cada uno 8x8)
 * @param num_tiles Número de tiles del actor (1,2,4)
 * @return índice inicial en VRAM
 */
uint8_t load_actor_tiles(Entity e, const unsigned char *tiles[], uint8_t num_tiles);
uint8_t load_extra_tiles(uint8_t id, const unsigned char *tiles, uint8_t num_tiles);

void reset_render_component(void);
void reset_extra_tiles(void);

#endif // LOAD_H