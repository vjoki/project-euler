#include <stdio.h>
#include "lib/common.h"

int main (int argc, char* argv[])
{
   if (argc!=2) {
      printf("Usage: %s <input file>",argv[0]);
      return 1;
   }
   unsigned triangle[100][100] = {0};
   
   FILE *f;
   f = fopen(argv[1], "rb");
   
   if (f!=NULL) {
      int ch, prev;
      unsigned i = 0, j = 0, chi = 0;
      while(ch!=EOF) {
         ch = fgetc(f);
         if (ch == '\n') {
            i++;
            j = 0;
            chi = 0;
         } else if (ch == ' ') {
            chi = 0;
            j++;
         } else {
            if(chi==1) {
               char tmp[2] = {prev,ch};
               triangle[i][j] = strtoul(tmp,NULL,10);
            } else {
               prev = ch;
               chi++;
            }
         }
      }
      if (fclose(f)!=0)
         return 1;
      
      while(i--) {
         for(j=0; j <= i; j++)
            triangle[i][j] += max_ui(triangle[i+1][j], triangle[i+1][j+1]);
      }
      printf("%u\n",triangle[0][0]);
   }
   return 0;
}