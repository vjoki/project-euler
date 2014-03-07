#include <stdio.h>

unsigned factor(unsigned n)
{
   unsigned f = 1;
   unsigned i;
   for (i=2;i<=n;i++)
      f *= i;
   return f;
}

unsigned factorial_sum(unsigned n)
{
   unsigned s = 0;
   unsigned x = n;
   
   while (x>0) {
      s += factor(x % 10);
      x /= 10;
   }
   
   if (s==n)
      return s;
   return 0;
}

int main(void)
{
   unsigned s = 0;
   unsigned i;
   for (i=3;i<100000;i++)
      s += factorial_sum(i);
   
   printf("%u\n",s);
   return 0;
}