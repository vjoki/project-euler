#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

int main(void)
{
   unsigned n = 1;
   mpz_t a,b,c;
   mpz_init_set_ui(a, 0);
   mpz_init_set_ui(b, 1);
   mpz_init(c);
   
   while(mpz_sizeinbase(b, 10) < 1000) {
      mpz_add(c,a,b);
      mpz_set(a,b);
      mpz_set(b,c);
      n++;
   }
   
   printf("%u\n",n);
   return 0;
}