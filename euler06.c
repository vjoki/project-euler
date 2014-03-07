#include <stdio.h>

int main(void)
{
   unsigned sumsq = 0, sqsum = 0;
   unsigned i;
   for (i=1;i<101;i++) {
      sqsum += i;
      sumsq += i*i;
   }
   sqsum *= sqsum;
   printf("%u\n",sqsum-sumsq);
   return 0;
}