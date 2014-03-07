#include <stdio.h>

int main(void) {
   unsigned maxlen = 0;
   unsigned maxi = 0;
   unsigned c, i;
   for (i=1;i<1000001;i++) {
      c = 1;
      unsigned long t = i;
      while (t!=1) {
         if (t % 2 == 0)
            t /= 2;
         else {
            t *= 3;
            t += 1;
         }
         c++;
      }
      if (c > maxlen) {
         maxlen = c;
         maxi = i;
      }
   }
   printf("start: %u length: %u\n",maxi,maxlen);
   return 0;
}