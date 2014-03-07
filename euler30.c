#include <stdio.h>
#include "lib/common.h"

unsigned char is_sum_of_pows(unsigned n, unsigned p)
{
   unsigned s = 0;
   unsigned x = n;
   unsigned d;
   while (x > 0) {
      d = x % 10;
      s += pow_ui(d,p);
      x /= 10;
   }
   if (s == n)
      return 1;
   return 0;
}

int main(int argc, char* argv[])
{
   unsigned s = 0;
   unsigned count = 0;

   unsigned i;
   for (i=2;i<1000000;i++) {
      if (is_sum_of_pows(i,5)) {
         count++;
         s += i;
      }
   }
   printf("%u S=%u\n",count,s);
   return 0;
}