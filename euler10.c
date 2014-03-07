#include <stdio.h>
#include "lib/common-math.h"

int main(void)
{
   unsigned long long sum = 0;
   unsigned i;
   for (i=2;i<2000000;i++) {
      if (is_prime(i))
         sum += i;
   }
   printf("%llu\n",sum);
   return 0;
}