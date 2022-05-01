#include <inttypes.h>
#include <stddef.h>

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
    {"addi", NULL, NULL, "001000"},
    {"and", "000000", "00000", "100100"},
    {"andi", NULL, NULL, "001100"},
    {"nor", "000000", "00000", "100111"},
    {"slti", NULL, NULL, "001010"},
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
    { "v0", "00010" },
	{ "v1", "00011" },
    { "s0", "10000" },
	{ "s1", "10001" },
	{ "s2", "10010" },
	{ "s3", "10011" },
	{ "s4", "10100" },
	{ "s5", "10101" },
	{ "s6", "10110" },
	{ "s7", "10111" },
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
   for (int i = 0; i < 8; i++)
   {
      if (strcmp(str, RegTable[i].regName) == 0)
      {
         return RegTable[i].regCode;
      }
   }

   return NULL;
}

