#include <stdio.h>
#include "lib/atkin.h"

unsigned prime_divisors(uint_fast64_t *primes, unsigned n)
{
   unsigned ndiv = n/2; // Not sure how small this can go. (sqrt(n) is too small)
   unsigned x = 0, i = 0;
   while (primes[i] > 0 && primes[i] <= ndiv) {
      if (n % primes[i++] == 0) {
         x++;
         if (x>3)
            break;
      }
   }
   return x;
}

int main(void)
{
   uint_fast64_t primes[1000] = {0};
   sieve_of_atkin(primes, 1000);
   unsigned c = 0;
   unsigned lasti = 0;
   unsigned i;
   for (i=1;i<1000000;i++) {
      if (prime_divisors(primes,i)>3) {
         if (lasti != 0 && i-1 == lasti)
            c++;
         else c = 0;
            
         if(c>2) {
            printf("%u\n",i-3);
            break;
         }
         lasti = i;
      }
   }
   return 0;
}