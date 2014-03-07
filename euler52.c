#include <stdio.h>
#include "lib/common.h"
#include "lib/common-math.h"

unsigned has_same_digits(unsigned a, unsigned b)
{
   unsigned digs = n_digits(a);
   if (digs == n_digits(b)) {
      unsigned digits[10] = {0};
      unsigned i;
      for (i=0;i<digs;i++)
         digits[nth_digit(a,i)]++;
      for (i=0;i<digs;i++) {
         if (digits[nth_digit(b,i)] == 0)
            return 0;
      }
      return 1;
   }
   return 0;
}

int main(void)
{
   unsigned c, i;
   for (i=1;i<999999;i++) {
      c = 2;
      while (has_same_digits(i,i*c)) c++;
      if (c>5) {
         printf("up to %ux, %u\n",c-1,i);
         break;
      }
   }
   return 0;
}