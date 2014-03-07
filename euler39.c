#include <stdio.h>
#include <math.h>

int main(void)
{
   unsigned pc[1001] = {0};
   unsigned p = 0, pcmax = 0, imax = 0;
   double dc;
   unsigned a,b,c;
   for (a=1;a<500;a++) {
      for (b=1;b<500;b++) {
         dc = sqrt(a*a+b*b);
         if (dc != (int)dc)
            continue;
         c = (unsigned)dc;
         p = a+b+c;
         if (p<1001)
            pc[p]++;
      }
   }
   
   for(a=1;a<1001;a++) {
      if (pc[a]>pcmax) {
         pcmax = pc[a];
         imax = a;
      }
   }
   printf("%ux p = %u\n",pcmax,imax);
   return 0;
}