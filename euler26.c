#include <stdio.h>
#include "lib/common-math.h"
#include "lib/mini-gmp/mini-gmp.h"

int main(int argc, char* argv[])
{
   const unsigned b = 10;
   unsigned cyclemax = 0, dmax = 0;
   unsigned t, r, p, d, x;
   mpz_t n;
   mpz_init(n);
   for (p=1;p<1000;p++) {
      if (is_prime(p) && 10 % p != 0) {
         t = 0;
         r = 1;
         mpz_set_ui(n, 0);
         while(t==0 || r!=1) {
            t++;
            x = r*b;
            d = (unsigned)x/p;
            r = x % p;
            mpz_mul_ui(n, n, b);
            mpz_add_ui(n, n, d);
         }
         if (t == p-1) {
            x = mpz_sizeinbase(n,10);
            if (x > cyclemax) {
               cyclemax = x;
               dmax = p;
            }
         }
      }
   }
   
   printf("max: 1/%u, %u digit cycle\n",dmax,cyclemax);
   return 0;
}