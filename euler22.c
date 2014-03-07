#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare (const void* a, const void* b)
{
   return strcmp((char*)a,(char*)b);
}

int strscore(char* n)
{
   static const char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int sum = 0;
   unsigned i;
   for (i=0;n[i];i++)
      sum += (strchr(alphabet, n[i]) - alphabet) + 1;
   return sum;
}

int main (int argc, char* argv[])
{
   if (argc!=2) {
      printf("Usage: %s <input file>",argv[0]);
      return 1;
   }
   
   FILE *f;
   f = fopen(argv[1], "rb");
   if (f!=NULL) {
      char names[5164][64] = {'\0'};
      unsigned nameindex = 0;
      size_t charpos;
      
      int ch;
      while (ch != EOF) {
         ch = fgetc(f);
         if (ch == ',') {
            nameindex++;
            charpos = 0;
         } else if (ch != '"' && ch != EOF) {
            charpos = strlen(names[nameindex]);
            if (charpos < 64)
               names[nameindex][charpos] = ch;
         }
      }
      if (fclose(f) != 0)
         return 1;
      
      qsort(names, nameindex+1, sizeof(names[0]), compare);
      
      int sum = 0;
      unsigned i;
      for (i=0;i<=nameindex;i++) {
         if (strlen(names[i]) > 0)
            sum += strscore(names[i]) * (i+1);
      }
      printf("%d\n",sum);
   }
   
   return 0;
}