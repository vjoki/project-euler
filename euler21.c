#include <stdio.h>

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
   unsigned amicable_sum = 0;
   unsigned a,b;
   
   unsigned i;
   for (i=1;i<=10000;i++) {
      a = sum_of_divisors(i);
      if (a>1 && a != i) {
         b = sum_of_divisors(a);
         if (b == i) {
            amicable_sum += a+b;
            //printf("amicable pair: a %u Sa %u | b %u Sb %u\n",i,a,a,b);
         }
      }
   }
   printf("%u\n",amicable_sum/2);
   return 0;
}