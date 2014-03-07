#include <stdio.h>
#include "lib/common.h"

int main(void)
{
   unsigned max = 0;
   unsigned i, j, prod;
   for (i=100;i<1000;i++) {
      for (j=100;j<1000;j++) {
         prod = i*j;
         if (max < prod && prod == reverse(prod))
            max = prod;
      }
   }
   printf("%u\n",max);
   return 0;
}