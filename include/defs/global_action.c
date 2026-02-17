#include "../action.h"
#include "../input.h"

void check_global_input(void)
{
    keys = joypad();

    // Actualizar last_keys para detectar cambios en la entrada
    prev_keys = keys;
}