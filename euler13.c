#include <stdio.h>
#include "lib/mini-gmp/mini-gmp.h"

int main (int argc, char* argv[])
{
   if (argc!=2) {
      printf("Usage: %s <input file>",argv[0]);
      return 1;
   }
   
   FILE *f;
   f = fopen(argv[1], "rb");
   char ch[52];
   mpz_t s;
   mpz_init(s);
   if (f != NULL) {
      while ( fgets(ch,52,f) != NULL ) {
         mpz_t c;
         mpz_init(c);
         mpz_set_str(c, ch, 10);
         mpz_add(s, s, c);
      } 
      if (fclose(f) != 0)
         return 1;
   }
   char* g = mpz_get_str(NULL, 10, s);
   
   if(mpz_sizeinbase(s,10)>10)
      printf("%.10s\n",g);
   return 0;
}