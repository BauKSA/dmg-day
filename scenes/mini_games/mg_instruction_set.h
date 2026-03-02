#ifndef _MG_INSTRUCTIONSET_
#define _MG_INSTRUCTIONSET_
#include <stdint.h>

typedef enum InstructionButton
{
    DPAD,
    A,
    B
} InstructionButton;

typedef struct Instruction
{
    char *text;
    InstructionButton button;
} Instruction;

void Mg_InstructionSet(Instruction *instructions, uint8_t instruction_count);

#endif // _MG_INSTRUCTIONSET_