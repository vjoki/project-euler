#include <stdio.h>
#include "lib/atkin.c"

uint_fast64_t *primes;

unsigned num_of_divisors(unsigned long long a)
{
   unsigned i = 0, n = 1;
   while(primes[i] != 0 && primes[i] <= sqrt(a)) {
      if (a % primes[i] == 0) {
         unsigned t = 0;
         unsigned long long tmp = a;
         while(tmp % primes[i] == 0) {
            tmp /= primes[i];
            t++;
         }
         n *= t+1;
      }
      i++;
   }
   return n;
}

int main(void)
{
   primes = calloc(1000+1,sizeof(uint_fast64_t));
   sieve_of_atkin(primes, 1000);
   
   unsigned long long n = 1;
   unsigned divs = 0;
   while(divs<501) {
      n++;
      divs = num_of_divisors((n*(n+1))/2);
   }
   
   printf("%llu. = %llu, %u divisors\n", n, (n*(n+1))/2, divs);
   free(primes);
   return 0;
}