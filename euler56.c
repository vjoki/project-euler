#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

unsigned digitsum(mpz_t z)
{
   unsigned sum = 0;
   char *pows = mpz_get_str(NULL, 10, z);
   size_t i, len = mpz_sizeinbase(z,10);
   for(i=0;i<len;i++)
      sum += pows[i]-'0';
   return sum;
}

int main(void)
{
   mpz_t powd;
   mpz_init(powd);
   mpz_t tmp;
   mpz_init(tmp);
   unsigned a,b, sum, maxsum = 0;
   for(a=1;a<100;a++) {
      mpz_set_ui(powd,a);
      for(b=1;b<100;b++) {
         mpz_pow_ui(tmp,powd,b);
         sum = digitsum(tmp);
         if (sum > maxsum)
            maxsum = sum;
      }
   }
   
   printf("%u\n",maxsum);
   return 0;
}