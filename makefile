assembler: assembler.c printToOutput.c
	gcc -g -std=c99 -o assemble -Wall assembler.c printToOutput.c
