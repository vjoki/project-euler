#include <stdio.h>
#include "lib/common-math.h"

int main(void)
{
   unsigned size = 3, primes  = 3, n = 5;
   do {
      size += 2;
      n += 4;
      
      unsigned a = size*size;
      if(is_prime(a)) primes++;
      if(is_prime(a - size+1)) primes++;
      if(is_prime(a - 2*size+2)) primes++;
      if(is_prime(a - 3*size+3)) primes++;
   } while(((double)primes/n) > 0.10);
   
   printf("%u\n",size);
   return 0;
}