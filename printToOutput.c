#include <inttypes.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Takes an integer and converts to binary
 *
 * @param num is the number in decimal form
 * @return char* is the parameter number in decimal
 **/
 
char *charDecToBin(int num)
{
   char* binary = calloc(16, sizeof(char ));
   int x, y;
   for (x = 15; x >= 0; x--)
   {
      y = num >> x;
      if (y & 1)
      {
         binary[15 - x] = '1';
      }
 
      else
      {
         binary[15 - x] = '0';
      }
   }
 
   return binary;
}

// Structure for Mnemonics names, their functs, and opcodes
struct _Mnem
{
   char *mnemName;   // Mnemonic name
   char *mnemOp;  // Mnemonic opcode
   char *mnemShamt;     // Mnemonic shamt
   char *mnemFunc;      // Mnemonic funct
};

typedef struct _Mnem Mnem;

static Mnem MnemTable[7] = {
    {"add", "000000", "00000", "100000"},
    {"addi", "001000", NULL, NULL},
    {"and", "000000", "00000", "100100"},
    {"andi", "001100", NULL, NULL},
    {"nor", "000000", "00000", "100111"},
    {"slti", "001010", NULL, NULL},
    {"syscall", "000000", NULL, "001100"}
};

/**
 * @brief Gets the funct of the mnemonic from the lookup table
 * 
 * @param str is the mnemonic name parameter
 * @return char* is the mnemonic's funct
 */
char *getMnemOp(const char *str)
{
   for (int i = 0; i < 7; i++)          // loops the amount of Mnemonics
   { 
      if (strcmp(str, MnemTable[i].mnemName) == 0)
      {                                 // determines if param is equal to any of the Mnemonics
         return MnemTable[i].mnemOp; // returns bin if register is found
      }
   }

   return NULL;
}

/**
 * @brief Gets the funct of the mnemonic from the lookup table
 * 
 * @param str is the mnemonic name parameter
 * @return char* is the mnemonic's funct
 */
char *getMnemShamt(const char *str)
{
   for (int i = 0; i < 7; i++)          // loops the amount of Mnemonics
   { 
      if (strcmp(str, MnemTable[i].mnemName) == 0)
      {                                 // determines if param is equal to any of the Mnemonics
         return MnemTable[i].mnemShamt; // returns bin if register is found
      }
   }

   return NULL;
}

/**
 * @brief Gets the funct of the mnemonic from the lookup table
 * 
 * @param str is the mnemonic name parameter
 * @return char* is the mnemonic's funct
 */
char *getMnemFunc(const char *str)
{
   for (int i = 0; i < 7; i++)          // loops the amount of Mnemonics
   { 
      if (strcmp(str, MnemTable[i].mnemName) == 0)
      {                                 // determines if param is equal to any of the Mnemonics
         return MnemTable[i].mnemFunc; // returns bin if register is found
      }
   }

   return NULL;
}

// Structure for Register names, their binary, and decimals
struct _Reg
{
   char *regName;    // Register name
   char *regCode;    // Register binary code
};

typedef struct _Reg Reg;

// Register table
static Reg RegTable[11] = {
   { "$v0", "00010" },
	{ "$v1", "00011" },
   { "$s0", "10000" },
	{ "$s1", "10001" },
	{ "$s2", "10010" },
	{ "$s3", "10011" },
	{ "$s4", "10100" },
	{ "$s5", "10101" },
	{ "$s6", "10110" },
	{ "$s7", "10111" },
   { NULL, 0}
};

/**
 * @brief Gets the binary for the register in the lookup table
 * 
 * @param str is the register name parameter
 * @return char* is the binary number of the register
 */
char *getRegBin(const char *str)
{
   for (int i = 0; i < 11; i++)
   {
      if (strcmp(str, RegTable[i].regName) == 0)
      {
         return RegTable[i].regCode;
      }
   }

   return NULL;
}

/**
 * @brief Prints an r type instruction without the immediate
 * 
 * @param instruction is the char version of the instruction
 * @param output is the file that the print statement points
 */
void printRegR(char* instruction, FILE* output) {
   char copy[100];
   strcpy(copy, instruction);
   
   char* temp = strtok(copy, " ");
   char* op = getMnemOp(temp);
   fprintf(output, "%s", op);

   char* reg1 = strtok(NULL, ", ");
   char* rd = getRegBin(reg1);

   char* reg2 = strtok(NULL, ", ");
   char* rs = getRegBin(reg2);

   char* reg3 = strtok(NULL, " \n\t");
   char* rt = getRegBin(reg3);

   fprintf(output, "%s", rs);
   fprintf(output, "%s", rt);
   fprintf(output, "%s", rd);

   char* shamt = getMnemShamt(temp);
   fprintf(output, "%s", shamt);
   char* func = getMnemFunc(temp);
   fprintf(output, "%s\n", func);
}  

/**
 * @brief Prints an r type instruction without the immediate
 * 
 * @param instruction is the char version of the instruction
 * @param output is the file that the print statement points
 */
void printAnd(char* instruction, FILE* output) {
   char copy[100];
   strcpy(copy, instruction);
   
   char* temp = strtok(copy, " \t");
   char* op = getMnemOp(temp);
   fprintf(output, "%s", op);

   char* reg1 = strtok(NULL, ", ");
   char* rd = getRegBin(reg1);

   char* reg2 = strtok(NULL, ", ");
   char* rs = getRegBin(reg2);

   char* reg3 = strtok(NULL, " \n\t");
   char* rt = getRegBin(reg3);

   fprintf(output, "%s", rs);
   fprintf(output, "%s", rt);
   fprintf(output, "%s", rd);

   char* shamt = getMnemShamt(temp);
   fprintf(output, "%s", shamt);
   char* func = getMnemFunc(temp);
   fprintf(output, "%s\n", func);
}  



void printRImm(char* instruction, FILE* output) {
   char copy[100];
   strcpy(copy, instruction);
   
   char* temp = strtok(copy, " ");
   char* op = getMnemOp(temp);
   fprintf(output, "%s", op);

   char* reg1 = strtok(NULL, ", ");
   char* rt = getRegBin(reg1);

   char* reg2 = strtok(NULL, ", ");
   char* rs = getRegBin(reg2);

   fprintf(output, "%s", rs);
   fprintf(output, "%s", rt);

   char* imm = strtok(NULL, " \n\t");
   char* imme = charDecToBin( atoi(imm));
   fprintf(output, "%s\n", imme); 

}


