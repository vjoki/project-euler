#include <stdio.h>
#include "lib/common-math.h"

unsigned char twice_a_square(unsigned n)
{
   double s = sqrt(n/2);
   if (s == (unsigned)s)
      return 1;
   return 0;
}

unsigned char is_goldbach(unsigned n)
{
   unsigned i;
   for (i=1;i<n;i+=2) {
      if (is_prime(i) == 1) {
            if (twice_a_square(n-i) == 1)
               return 1;
      }
   }
   return 0;
}

int main(void)
{
   unsigned i;
   for (i=9;i<999999;i+=2) {
      if (is_prime(i) == 0 && is_goldbach(i) == 0) {
         printf("Goldbach failed, %d\n",i);
         break;
      }
   }
   return 0;
}