#include <stdio.h>
#include "lib/common.h"

int main(void)
{
   char n[] = "0123456789";
   unsigned i;
   for (i=1;i<1000000;i++)
      next_permutation(n,10);
      
   printf("%u. %s\n",i,n);
   return 0;
}