#include <stdio.h>
#include <stdlib.h>
#include "lib/common.h"

int main (int argc, char* argv[])
{
   if (argc!=2) {
      printf("Usage: %s <input file>",argv[0]);
      return 1;
   }
   unsigned digits[10] = {0};
   unsigned idx = 0, codelen = 0;
   unsigned *keylog;
   FILE *f;
   f = fopen(argv[1],"rb");
   
   fseek(f, 0, SEEK_END);
   long int size = ftell(f)/sizeof(char) + 1;
   fseek(f, 0, SEEK_SET);
   keylog = calloc(size, sizeof(unsigned));
   
   if (f!=NULL) {
      int ch;
      while(ch!=EOF) {
         ch = fgetc(f);
         if (ch != '\n') {
            unsigned tmp = ch-'0';
            keylog[idx++] = tmp;
            digits[tmp]++;
            if (digits[tmp]==1)
               codelen++;
         }
      }
      if (fclose(f) != 0)
         return 1;
      
      unsigned code[codelen];
      unsigned i, codeidx = 0;
      for(i=0;i<10;i++) {
         if (digits[i] > 0)
            code[codeidx++] = i;
      }
      
      unsigned j;
      for(i=0;i<idx;i+=3) {
         unsigned a = 0, b = 0, c = 0;
         for(j=0;j<codelen;j++) {
            if (code[j] == keylog[i+2])
               a = j;
            if (code[j] == keylog[i+1])
               b = j;
            if (code[j] == keylog[i])
               c = j;
         }
         
         if (a < b)
            swap_ui(&code[a], &code[b]);
         if (b < c)
            swap_ui(&code[b], &code[c]);
      }
      
      for(i=0;i<codelen;i++)
         printf("%u",code[i]);
      printf("\n");
   }
   return 0;
}