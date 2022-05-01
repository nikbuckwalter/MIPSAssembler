assembler: assembler.c Registers.c printToOutput.c
	gcc -g -std=c99 -o assemble -Wall assembler.c Registers.c printToOutput.c
