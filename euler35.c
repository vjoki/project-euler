#include <stdio.h>
#include "lib/common-math.h"

int main(void)
{
   unsigned i,c = 0;
   for (i=2;i<1000000;i++) {
      if (is_prime(i)) {
         unsigned len = n_digits(i);
         unsigned char discard = 0;
         
         unsigned j,tmp = i;
         for (j=1;j<len;j++) {
            tmp = (tmp/10) + (tmp%10) * ceil(pow(10,floor(log10(tmp))));
            if (is_prime(tmp) == 0) {
               discard = 1;
               break;
            }
         }
         
         if (discard==0)
            c++;
      }
   }
   printf("%u\n",c);
   return 0;
}