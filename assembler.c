#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

static FILE* fp;
static FILE* fp2;
static FILE* out;

void printRegR(char* instruction, FILE* output);

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

int main (int argc, char* argv[]) {
   fp = fopen(argv[1], "r");

   if (fp != NULL) {
      out = fopen(argv[2], "w");
   }

   fp2 = fopen("output2.txt", "w");
   

   if (fp == NULL || out == NULL) {
      printf("file can't be opened \n");
      return 0;
   }

   char* ch = calloc(256, sizeof(char));
   while (fgets(ch, 256, fp) != NULL) {
      if(strstr(ch, "add") || strstr(ch, "nor") || strstr(ch, "and")) {

         if (strstr(ch, "#")) {
            continue;
         }
         else {
            printRegR(ch, out);
         }
      }
   }
   free(ch);
   fclose(fp);

   return 0;
}


