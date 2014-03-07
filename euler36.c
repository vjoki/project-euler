#include <stdio.h>
#include "lib/common.h"

unsigned long long base10to2(unsigned n)
{
   if (n == 0) return n;
   return (n % 2) + 10 * base10to2(n / 2);
}

unsigned char is_palindrome_ull(unsigned long long n)
{
   if (n==reverse_ull(n)) return 1;
   return 0;
}

int main(void)
{
   unsigned sum = 0;
   unsigned i;
   for(i=1;i<1000000;i++) {
      if (is_palindrome_ull(i) && is_palindrome_ull(base10to2(i)))
         sum += i;
   }
   printf("%u\n",sum);
   return 0;
}