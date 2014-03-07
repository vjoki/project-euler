#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

int main(void)
{
   mpz_t sum, mod, modpow, mpzi;
   mpz_init(sum);
   mpz_init(mod);
   mpz_init(modpow);
   mpz_init(mpzi);
   mpz_ui_pow_ui(mod, 10, 10);
   
   unsigned i;
   for(i=1;i<1000;i++) { // can skip 1000^1000
      mpz_set_ui(mpzi, i);
      mpz_powm(modpow, mpzi, mpzi, mod);
      mpz_add(sum, sum, modpow);
   }
   
   mpz_mod(modpow, sum, mod);
   char *c = mpz_get_str(NULL, 10, modpow);
   printf("%s\n",c);
   return 0;
}