#include <stdio.h>
#include "lib/common-math.h"

int main(void)
{
   unsigned p[28665] = {0};
   unsigned pidx = 0;
   unsigned i;
   for (i=2;i<333333;i++) {
      if (is_prime(i))
         p[pidx++] = i;
   }
   
   unsigned cps, count;
   unsigned lastcps = 0;
   unsigned lastcount = 0;
   unsigned maxcount = 0;
   unsigned offset = 0;
   while(offset<pidx) {
      cps = 0;
      count = 0;
      for (i=offset;i<pidx;i++) {
         cps += p[i];
         count++;
         if (cps < 999999) {
            if (is_prime(cps)) {
               lastcount = count;
               lastcps = cps;
            }
         } else break;
      }
      if (lastcount>maxcount) {
         maxcount = lastcount;
         printf("beat last max: %d primes, S = %d\n", maxcount, lastcps);
      }
      offset++;
   }
   
   return 0;
}