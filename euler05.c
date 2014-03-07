#include <stdio.h>

int main(void)
{
   unsigned n = 2520;
   unsigned i = 1;
   while(i < 21) {
      n++;
      i = 1;
      while (i < 21 && n % i == 0)
         i++;
   }
   printf("%u\n",n);
   return 0;
}