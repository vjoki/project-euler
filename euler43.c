#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.c"
#include "lib/common.h"

int substrint(char *d, unsigned f, unsigned l)
{
   char tmp[l];
   unsigned i;
   for (i=0;i<l;i++)
      tmp[i] = d[f+i];
   tmp[l] = '\0';
   return atoi(tmp);
}

int main(void)
{
   char dict[] = "1234567890";
   const unsigned p[] = {2,3,5,7,11,13,17};
   
   mpz_t dint, sum;
   mpz_init(dint);
   mpz_init(sum);
   
   unsigned char ret = 1;
   unsigned i;
   while(ret == 1) {
      mpz_set_str(dint, dict, 10);
         for (i=0;i<7;i++) {
            if (substrint(dict, i+1, 3) % p[i] != 0) {
               mpz_set_ui(dint, 0);
               break;
            }
         }
         if (mpz_sgn(dint)>0)
            mpz_add(sum, sum, dint);
      ret = next_permutation(dict,10);
   }
   char *s = mpz_get_str(NULL, 10, sum);
   printf("%s\n",s);
   return 0;
}