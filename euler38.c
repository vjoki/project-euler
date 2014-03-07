#include <stdio.h>
#include "lib/common.h"

int main(void)
{
   unsigned lastmax = 0;
   unsigned ret, cat, mul;
   
   unsigned i, j;
   for (i=9;i<9999;i++) {
      cat = 0;
      for (j=1;j<4;j++) {
         mul = i*j;
         if (digits(mul) > 0) {
            cat = combine_uis(cat,mul);
            ret = digits(cat);
            if (ret < 0)
               break;
            else if (ret == 0) {
               if (cat > lastmax)
                  lastmax = cat;
            }
         } else 
            break;
      }
   }
   printf("%u\n",lastmax);
   return 0;
}
