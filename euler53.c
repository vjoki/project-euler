#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

void factorial(mpz_t r, unsigned x)
{
   if(x==0) x = 1;
   
   mpz_set_ui(r, x);
   
   while(x>1) {
      x--;
      mpz_mul_ui(r,r,x);
   }
}

int main(void)
{
   mpz_t f_n, f_r, tmp;
   mpz_init(f_n);
   mpz_init(f_r);
   mpz_init(tmp);
   unsigned count = 0;
   
   unsigned n;
   for(n=23;n<101;n++) {
      unsigned r;
      for(r=1;r<=n;r++) {
         factorial(tmp, n);
         mpz_set(f_n, tmp);
         
         factorial(tmp, r);
         mpz_set(f_r, tmp);
         
         factorial(tmp, n - r);
         mpz_mul(f_r, f_r, tmp);
         
         mpz_fdiv_q(f_n, f_n, f_r);
         
         if(mpz_cmp_ui(f_n, 1000000) > 0)
            count++;
      }
   }
   
   printf("%u\n",count);
   return 0;
}