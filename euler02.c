#include <stdio.h>

int main(void)
{
   unsigned a = 0, b = 1, c;
   unsigned sum = 0;
   while(b < 4000000) {
      c = a+b;
      a = b;
      b = c;
      if (b % 2 == 0)
         sum += b;
   }
   printf("%u\n",sum);
   return 0;
}