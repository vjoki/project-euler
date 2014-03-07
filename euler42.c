#include <stdio.h>
#include <string.h>
#include <math.h>

unsigned char is_triangle(unsigned n) {
   double inverse = (-1+sqrt(8*n+1))/2;
   if (inverse == (int)inverse) return 1;
   return 0;
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
   
   char words[2000][64] = {'\0'};
   unsigned idx = 0;
   size_t charpos;

   FILE *f;
   f = fopen(argv[1], "rb");
   if (f!=NULL) {
      int ch;
      while (ch != EOF) {
         ch = fgetc(f);
         if (ch == ',') {
            idx++;
            charpos = 0;
         } else if (ch != '"' && ch != EOF) {
            charpos = strlen(words[idx]);
            if (charpos < 64)
               words[idx][charpos] = ch;
         }
      }
      if (fclose(f) != 0)
         return 1;
   }
   
   unsigned count = 0;
   unsigned i;
   for (i=0;i<idx;i++) {
      if (is_triangle(strscore(words[i])))
         count++;
   }
   
   printf("%u\n",count);
   return 0;
}