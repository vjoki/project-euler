#include <stdio.h>
#include "lib/common.h"

int main(void)
{
   unsigned numer = 1, denom = 1;
   unsigned a, b, c;
   for (a=1;a<10;a++) for (b=1;b<10;b++) for (c=1;c<10;c++)
   if ( a/c < 1 && (double)(a*10+b)/(b*10+c) == (double)a/c ) {
      printf("%u%u/%u%u = %u/%u\n",a,b,b,c,a,c);
      numer *= a;
      denom *= c;
   }
   printf("product: %u/%u = %u/%u\n", numer, denom, numer/gcd(numer,denom), denom/gcd(numer,denom));
   return 0;
}