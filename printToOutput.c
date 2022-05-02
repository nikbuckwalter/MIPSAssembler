#include <inttypes.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "Registers.h"

void printRegR(char* instruction, FILE* output) {
    char* mnemonic = strtok(instruction, " ");
    fprintf(output, "%s", mnemonic);
    char* Op = getMnemOp(mnemonic);
    fprintf(output, "%s", Op);

    
    

}
