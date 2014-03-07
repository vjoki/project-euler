#include <stdio.h>
#include "lib/common.h"
#include "lib/common-math.h"

int main(void)
{
   unsigned tmp, n, sum = 0;
   unsigned i = 11;
   unsigned char c = 0;
   while (c<11) {
      if (is_prime(i)) {
         tmp = i/10;
         while (tmp>10 && is_prime(tmp))
            tmp /= 10;
            
         if (tmp==2 || tmp==3 || tmp==5 || tmp==7) {
            n = n_digits(i);
            
            while (n>0 && is_prime(i % pow_ui(10,n)))
               n--;
            
            if (n == 0) {
               sum += i;
               ++c;
            }
         }
      }
      i++;
   }
   printf("%u\n",sum);
   return 0;
}