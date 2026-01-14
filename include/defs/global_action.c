#include "../action.h"

void check_global_input(void)
{
    uint8_t keys = joypad();

    // Actualizar last_keys para detectar cambios en la entrada
    last_keys = keys;
}