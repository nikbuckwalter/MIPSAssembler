#include <inttypes.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "Registers.h"

void printRegR(char* instruction, FILE* output) {
    char* mnemonic = strtok(instruction, " ");
    fprintf(output, "%s", mnemonic);
    char* rd = strtok(instruction, ", ");
    fprintf(output, "%s", rd);
    char* rs = strtok(instruction, ", ");
    fprintf(output, "%s", rs);
    char* rt = strtok(instruction, ", ");
    fprintf(output, "%s", rt);
    

}
