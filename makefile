assembler: assembler.c Registers.c printToOutput.c
	gcc -std=c99 -o assemble -Wall assembler.c Registers.c printToOutput.c
