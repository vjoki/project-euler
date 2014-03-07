#include <stdio.h>
#include <math.h>

unsigned char is_pentagon(unsigned s)
{
   double inverse = (1+sqrt(24*s+1))/6;
   if (inverse == (int)inverse) return 1;
   return 0;
}

int main(void)
{
   unsigned mindiff = 0;
   unsigned diff = 0;
   unsigned pj, pk, i, j;
   for(i=1;i<9999;i++) {
      pj = i*(3*i-1)/2;
      for(j=9999;j>(i+1);j--) {
         pk = j*(3*j-1)/2;
         diff = pk-pj;
         if (is_pentagon(diff) && is_pentagon((pk+pj))) {
            if (mindiff==0 || diff<mindiff)
               mindiff = diff;
         }
      }
   }
   printf("%u\n", mindiff);
   return 0;
}