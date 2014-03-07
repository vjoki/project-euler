#include <stdio.h>

int main(void)
{
   unsigned long p,h;
   unsigned i,j;
   for (i=143;i<99999;i++) {
      h = i*(2*i-1);
      p = 0; j = 165+(i-143);
      while (p<=h) {
         p = j*((3*j-1)/2);
         if (p == h && ((2*i-1)*((2*i)/2)) == h)
               printf("T%u = H%u = P%u = %lu\n",(2*i-1),i,j,h);
         j++;
      }
   }
   return 0;
}