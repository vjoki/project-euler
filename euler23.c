#include <stdio.h>
#include <math.h>

unsigned sum_of_divisors(unsigned n)
{
   if (n<0)
      n *= -1;
   unsigned sum = 0;
   unsigned ndiv = n/2;
   
   if (n % 2 == 0)
      sum += ndiv;
   
   unsigned i;
   for (i=1;i<ndiv;i++) {
      if (n % i == 0)
         sum += i;
   }
   return sum;
}

int main(void)
{
   unsigned abus[10000] = {0};
   unsigned abuidx = 0;
   
   unsigned i;
   for (i=12;i<20162;i++) {
      if (i < sum_of_divisors(i))
         abus[abuidx++] = i;
   }
   
   unsigned numnums[20161] = {0};
   for (i=0;i<20161;i++)
      numnums[i] = (i+1);
   
   unsigned j;
   unsigned asum = 0;
   for (i=0;i<abuidx;i++) {
      for (j=0;j<abuidx;j++) {
         asum = (abus[i] + abus[j]);
         if (asum <= 20161)
            numnums[asum-1] = 0;
      }
   }
   
   unsigned tsum = 0;
   for (i=0;i<20161;i++)
      tsum += numnums[i];
   
   printf("%u\n",tsum);
   return 0;
}