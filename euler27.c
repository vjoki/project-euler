#include <stdio.h>
#include "lib/common-math.h"

unsigned quadratics(int a, int b, unsigned limit)
{
   unsigned counter = 0;
   int q = 0;
   int n;
   for (n=0;n<limit;n++) {
      q = (n*n) + (a*n) + b;
      if (q > 1 && is_prime(q) == 1)
         counter++;
      else
         break;
   }
   return counter;
}

int main(void)
{
   int product = 0;
   unsigned q, maxq = 0;
   int a,b;
   for (a=-999;a<1000;a++) {
      for (b=-999;b<1000;b++) {
         q = quadratics(a, b, 1000);
         
         if (q != 0 && q > maxq) {
            maxq = q;
            product = a * b;
         }
      }
   }
   printf("%u primes, product = %d\n", maxq, product);
   
   return 0;
}