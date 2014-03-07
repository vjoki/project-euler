#include <stdio.h>

int main(void)
{
   unsigned a, b, c, m, n;
   for (m=1;m<500;m++) {
      for (n=1;n<m;n++) {
         a = 2 * m * n;
         b = m*m - n*n;
         c = m*m + n*n;
         if ((a+b+c) == 1000) {
            printf("%u\n",a*b*c);
            return 0;
         }
      }
   }
   return 1;
}