#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

static FILE *fp;
static FILE *out;

/**
 * @brief Takes an integer and converts to binary
 * 
 * @param num is the number in decimal form
 * @return char* is the parameter number in decimal
 */
char *DecToBin(int num)
{
   char* binary = calloc(16, sizeof(char *));
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

int main (int argc, char *argv[]) {
   fp = fopen(argv[1], "r");
   out = fopen(argv[2], "w");

   if (fp == NULL || out == NULL) {
      printf("file can't be opened \n");
   }

   char ch = calloc(256, sizeof(char));
   ch = fgetc(fp);
   printf("%c", ch);
   fclose(fp);
}


