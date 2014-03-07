#include <stdio.h>
#include "lib/common.h"
#include "lib/common-math.h"

unsigned long long has_sequence_perms(unsigned n)
{
   unsigned pperms[25] = {0};
   unsigned idx = 0;
   
   char buf[5];
   snprintf(buf, 5, "%u", n);
   
   unsigned char ret = 1;
   unsigned tmp;
   while(ret == 1) {
      tmp = strtoul(buf,NULL,10);
      if (is_prime(tmp))
         pperms[idx++] = tmp;
      ret = next_permutation(buf,3);
   }
   
   if (idx>2) {
      unsigned i,j;
      for (i=0;i<idx;i++) {
         for (j=i+1;j<idx;j++) {
            tmp = pperms[j] - pperms[i];
            if (find_ui_in_array(pperms,idx,pperms[j]+tmp)) {
               return combine(pperms[i], combine(pperms[j], pperms[j]+tmp));
            }
         }
      }
   }
   return 0;
}

int main(void)
{
   unsigned long long match = 0;
   unsigned i;
   for (i=1000;i<9999;i++) {
      if (is_prime(i)) {
         match = has_sequence_perms(i);
         if (match>0)
            printf("%llu %u\n", match, i);
      }   
   }
   return 0;
}
