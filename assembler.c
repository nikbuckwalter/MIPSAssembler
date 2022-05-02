#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
 
static FILE* fp;
static FILE* out;
 
void printRegR(char* instruction, FILE* output);
void printRImm(char* instruction, FILE* output);
void printAnd(char* instruction, FILE* output);
 
int main (int argc, char* argv[]) {
   fp = fopen(argv[1], "r");
 
   if (fp != NULL) {
      out = fopen(argv[2], "w");
   }
 
   if (fp == NULL || out == NULL) {
      printf("file can't be opened \n");
      return 0;
   }
 
   char* ch = calloc(256, sizeof(char));
   while (fgets(ch, 256, fp) != NULL) {
      if (strstr(ch, "addi")) {
         if(strstr(ch, "#")) {
            continue;
         }
         else {
            printRImm(ch, out);
         }
      }
      else if(strstr(ch, "add")) {
 
         if (strstr(ch, "#")) {
            continue;
         }
         else {
            printRegR(ch, out);
         }
      }

      if(strstr(ch, "nor")) {
 
         if (strstr(ch, "#")) {
            continue;
         }
         else {
            printRegR(ch, out);
         }
      }

      if (strstr(ch, "andi")) {
         if(strstr(ch, "#")) {
            continue;
         }
         else {
            printRImm(ch, out);
         }
      }
      else if(strstr(ch, "and")) {
         if (strstr(ch, "#")) {
            continue;
         }
         else {
            printAnd(ch, out);
         }
      }

      if (strstr(ch, "slti")) {
         if(strstr(ch, "#")) {
            continue;
         }
         else {
            printRImm(ch, out);
         }
      }

      if (strstr(ch, "syscall")) {
         if(strstr(ch, "#")) {
            continue;
         }
         else {
            fprintf(out, "%s", "00000000000000000000000000001100");
         }
      }

   }
   free(ch);
   fclose(fp);
 
   return 0;
}
