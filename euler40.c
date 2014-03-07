#include <stdio.h>
#include "lib/common.h"
#include "lib/common-math.h"

int main(void)
{
   unsigned prod = 1; // d1*d10 = 1*1
   unsigned tmp;
   unsigned n = 1;
   unsigned i = 2;
   while(n<=1000000) {
      tmp = n_digits(i);
      while (tmp--) {
         n++;
         if (n==1000000 || 
             n==100000 || 
             n==10000 || 
             n==1000 || 
             n==100) prod *= nth_digit(i,tmp);
      }
      i++;
   }
   printf("%u\n",prod);
   return 0;
}