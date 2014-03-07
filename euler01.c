#include <stdio.h>

int main(void)
{
   unsigned i, sum = 0;
   for (i=3;i<1000;i++) {
      if (i % 3 == 0 || i % 5 == 0)
         sum += i;
   }
   printf("%u\n",sum);
   return 0;
}