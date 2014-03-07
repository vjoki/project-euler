#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

int main(void)
{
   mpz_t n;
   mpz_init(n);
   mpz_ui_pow_ui(n,2,1000);
   
   char *c = mpz_get_str(NULL, 10, n);
   unsigned i, sum = 0;
   for (i=0;i<mpz_sizeinbase(n, 10);i++)
      sum += c[i] - '0';
   
   printf("%u\n",sum);
   return 0;
}