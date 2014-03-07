#include <stdio.h>

long long bin_coef(unsigned n, unsigned k)
{
   if (k < 0 || k > n) return 0;
   if (k == 0 || k == n) return 1;
   if (k > n-k) return n-k;

   long long res = 1;
   unsigned i;
   for (i=1;i<=k;i++) {
      res *= (n - (k - i));
      if (res < 0) return -1;
      res /= i;
   }
   return res;
}

int main(void)
{
   printf("%lld\n",bin_coef(20+20,20));
   return 0;
}
