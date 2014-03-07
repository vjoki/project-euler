#include <stdio.h>
#include "lib/common.h"
#include "lib/common-math.h"

unsigned long find_max_panprime(char* dict, unsigned len)
{
   unsigned long maxprim = 0;
   unsigned long dint;
   unsigned char ret = 1;
   
   while (ret == 1) {
      dint = strtoul(dict,NULL,10);
      if (is_prime_l(dint) == 1 && dint > maxprim)
         maxprim = dint;
         
      ret = next_permutation(dict,len);
   }
   return maxprim;
}

int main(void)
{
   char dict[] = "1234567";
   printf("%ld\n",find_max_panprime(dict,7));
   return 0;
}