#include <stdio.h>
#include "lib/common-math.h"

int main(void)
{
   unsigned i = 0, p = 0;
   while (p<10001) {
      i++;
      if (is_prime(i))
         p++;
   }
   printf("%u\n",i);
   return 0;
}