#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"
#include "lib/common.h"

void reverse_mpz(const mpz_t n, mpz_t r)
{
   mpz_t nt;
   mpz_init_set(nt, n);
   mpz_set_ui(r, 0);
   while (mpz_sgn(nt) > 0) {
      mpz_mul_ui(r,r,10);
      mpz_add_ui(r,r,mpz_fdiv_q_ui(nt,nt,10));
   }
}

int main(void)
{
   // We get the right result with long long but the numbers grow too large
   // and we can't be certain, thus gmp.
   mpz_t sum, res;
   mpz_init(sum);
   mpz_init(res);
   
   unsigned count = 0;
   unsigned i;
   for(i=1;i<10000;i++) {
      mpz_set_ui(sum, i+reverse_ull(i));
      reverse_mpz(sum,res);
      if (mpz_cmp(sum,res)!=0) {
         unsigned j;
         for(j=1;j<50;j++) {
            reverse_mpz(sum,res);
            mpz_add(sum,sum,res);
            reverse_mpz(sum,res);
            if (mpz_cmp(sum,res)==0)
               break;
         }
         
         if (j==50 && mpz_cmp(sum,res)!=0)
            count++;
      }
   }
   printf("%u\n",count);
   return 0;
}
