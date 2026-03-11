#ifndef _MG_INSTRUCTIONSET_
#define _MG_INSTRUCTIONSET_
#include <stdint.h>

typedef enum InstructionButton
{
    DPAD,
    A,
    B
} InstructionButton;

typedef struct Requirement
{
    char *text;
    uint8_t qty;
} Requirement;

typedef struct Instruction
{
    char *text;
    InstructionButton button;
} Instruction;

void Mg_InstructionSet(Instruction *instructions, uint8_t instruction_count, Requirement *reqs, uint8_t reqs_count);

#endif // _MG_INSTRUCTIONSET_