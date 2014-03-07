#include <stdio.h>
#include <math.h>

unsigned char has_dupes(double (*l)[99], double n, unsigned maxi)
{
   unsigned i,j;
   for (i=0;i<=maxi;i++) {
      for (j=0;j<99;j++) {
         if (l[i][j] == n)
            return 1;
      }
   }
   return 0;
}

int main(void)
{
   double pows[99][99] = {0.0};
   unsigned count = 0;
   // volatile = workaround, otherwise wrong result if optimized by compiler
   volatile double tmp = 0.0;
   
   unsigned i,j;
   for (i=2;i<101;i++) {
      for (j=2;j<101;j++) {
         tmp = pow(i,j);
         if (has_dupes(&pows[0],tmp,i) == 0) {
            count++;
            pows[i-2][j-2] = tmp;
         }
      }
   }
   printf("%u\n",count);
   return 0;
}