#include <stdio.h>

int main(void)
{
   unsigned perms = 1;
   unsigned a, b, c, d, e, f, g;
   // nice pyramid
   for (a=0;a<201;a++) {
      for (b=0;b<201;b+=2) {
         for (c=0;c<201;c+=5) {
            for (d=0;d<201;d+=10) {
               for (e=0;e<201;e+=20) {
                  for (f=0;f<201;f+=50) {
                     for (g=0;g<201;g+=100) {
                        if ((a+b+c+d+e+f+g)==200) perms++;
                     }
                  }
               }
            }
         }
      }
   }
   printf("%u\n",perms);
   return 0;
}