#include <stdio.h>
#include "lib/common.h"

int main(void)
{
   unsigned sum = 0;
   unsigned panprods[32] = {0};
   unsigned idx = 0;
   
   unsigned long long muls;
   unsigned i,j;
   for (i=1;i<999;i++) {
      for (j=1;j<9999;j++) {
         muls = combine(i,j);
         if (digits_ull(muls) > 0) {
            unsigned prod = i*j;
            if (digits_ull(combine(muls,prod)) == 0) {
               if (idx<32 && find_ui_in_array(panprods,idx,prod) == 0) {
                  printf("%u * %u = %u\n",i,j,prod);
                  panprods[idx++] = prod;
                  sum += prod;
               }
            }
         }
      }
   }
   printf("%ux, S = %u\n",idx,sum);
   return 0;
}
