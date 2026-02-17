#ifndef _NPCDIALOGUES_
#define _NPCDIALOGUES_
#include "./npcs.h"
#include "./scene.h"

typedef char Line[18];
typedef Line Dialogue[2];

typedef Dialogue DialoguePerHumor[3];
typedef DialoguePerHumor DialoguePerRelation[3];

/**
 * [---------- DIALOGOS: ----------]
 * La idea acá es definir todas las instancias de diálogos
 * de los NPC
 * Va a haber 3 instancias de diálogo:
 *
 * 1- Diálogo inicial (saludo)
 * 2- Diálogo de misión/evento
 * 3- Diálogo final
 *
 * Cada instancia tendrá 3 diálogos (2 líneas cada uno)
 * dependiendo del humor/relación:
 *
 * Mal humor
 * Neutral
 * Buen humor
 * 
 * y por cada uno 3 variantes según relación:
 * 
 * Mala
 * Neutra
 * Buena
 * 
 * El primer díalogo siempre empieza con relación NEUTRA
 * Así quedan las variantes:
 * 
 * Diálogo 1:
 * Relación Neutra:
 * Humor: Malo / Neutro / Bueno
 * Total: 3 diálogos.
 * 
 * Diálogo 2:
 * Relación Buena:
 * Humor: Malo / Neutro / Bueno
 * Relación Mala:
 * Humor: Malo / Neutro / Bueno
 * Total: 6 diálogos.
 * 
 * Diálogo 3:
 * Relación Buena:
 * Humor: Malo / Neutro / Bueno
 * Relación Mala:
 * Humor: Malo / Neutro / Bueno
 * Total: 6 diálogos.
 * 
 * Total de variantes por NPC
 * 15 diálogos
 * 
 * HOWTO:
 * Cómo acceder a los diálogos?
 * dialogue[relation][humor]
 */

extern DialoguePerRelation* CurrentNPCDialogues[MAX_NPCS_PER_SCENE];

#endif //_NPCDIALOGUES_