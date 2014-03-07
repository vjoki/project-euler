#include "common-math.h"

unsigned n_digits(unsigned n)
{
   return (unsigned)log10(n) + 1;
}

unsigned char is_prime(unsigned n)
{
   if (n<2)
      return 0;
   unsigned i;
   for (i=2;i<=sqrt(n);i++) {
      if (n%i == 0)
         return 0;
   }
   return 1;
}
unsigned char is_prime_l(unsigned long n)
{
   if (n<2)
      return 0;
   unsigned long i;
   for (i=2;i<=sqrt(n);i++) {
      if (n%i == 0)
         return 0;
   }
   return 1;
}