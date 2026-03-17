#ifndef _MG_COINSREWARD_
#define _MG_COINSREWARD_
#include <stdint.h>

/**
 * TABLA DE PUNTAJES MINI-JUEGOS
 * Pasando puntaje mínimo:
 * R/H |  malo | neutro | bueno
 * -----------------------------
 * B   | 3.500 | 3.800  | 4.200
 * -----------------------------
 * M   | 2.100 | 2.300  | 2.500
 *
 * Sin puntaje mínimo:
 * R/H |  malo | neutro | bueno
 * -----------------------------
 * B   | 800   | 900    | 1.000
 * -----------------------------
 * M   | 500   | 600    | 700
 */

uint16_t Mg_SetCoinsReward(uint8_t npc_map, uint8_t success);

#endif
