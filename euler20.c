#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

int main(void)
{
   unsigned n = 100, sum = 0;
   mpz_t fac;
   mpz_init_set_ui(fac, n);
   
   while(n-- > 1)
      mpz_mul_ui(fac, fac, n);
   while(mpz_sgn(fac) > 0)
      sum += mpz_fdiv_q_ui(fac, fac, 10);
   
   printf("%u\n",sum);
   return 0;
}