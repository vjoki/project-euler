#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ONE_DIGIT_LEN 4
#define MAX_DIGIT_LEN 10
#define MAX_NUMBER_LEN 44

const char dict[3][9][MAX_DIGIT_LEN] = {
   {"one","two","three","four","five","six","seven","eight","nine"},
   {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"},
   {"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"}
};

unsigned split_int(unsigned *n, unsigned lim)
{
   unsigned c = 0;
   while ((*n) >= lim) {
      (*n) -= lim;
      c++;
   }
   return c;
}

void number_to_words(char* out, unsigned n)
{
   if (n > 9999)
      return;
   
   unsigned c;
   
   if (n >= 100) {
      unsigned char f = 0;
      if (n >= 1000) f++;
      
      if (f) c = split_int(&n,1000);
      else   c = split_int(&n,100);
      
      char p[ONE_DIGIT_LEN + MAX_DIGIT_LEN + 3];
      number_to_words(&p[0],c);
      strcpy(out,p);
      
      if (f) strcat(out,"thousand");
      else   strcat(out,"hundred");
      
      if (n>0) {
         strcat(out,"and");
         number_to_words(&p[0],n);
         strcat(out,p);
      }
   } else if (n >= 10) {
      c = split_int(&n,10);
      if (c==1 && n>0) {
         strcpy(out, dict[1][n-1]);
      } else {
         strcpy(out, dict[2][c-1]);
         if (n>0) {
            char p[ONE_DIGIT_LEN];
            number_to_words(&p[0],n);
            strcat(out,p);
         }
      }
   } else if (n<10)
      strcpy(out, dict[0][n-1]);
   else out = "";
}

int main(int argc, char* argv[])
{
   if (argc>1) {
      unsigned count = strtoul(argv[1],NULL,10);
      if (count>0 && count<10000) {
         char p[MAX_NUMBER_LEN];
         number_to_words(&p[0],count);
         printf("%u = %s, length: %u\n",count,p,strlen(p));
      }
   } else {
      unsigned i;
      unsigned sum = 0;
      char p[MAX_NUMBER_LEN];
      for (i=1;i<=1000;i++) {
         number_to_words(&p[0],i);
         sum += strlen(p);
      }
      printf("number words from 1 to 1000 length: %u\n",sum);
   }
   return 0;
}