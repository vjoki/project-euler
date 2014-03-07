#include <stdio.h>
#include "lib/common-math.h"

int main(void)
{
   unsigned max = 0;
   unsigned long long n = 600851475143;
   unsigned a = 2;
   while (a <= sqrt(n)) {
      if (n % a == 0 && is_prime(a))
         max = a;
      a++;
   }
   printf("%u\n",max);
   return 0;
}