#include "common.h"

/**************************************
 * MATH
 **************************************/

unsigned max_ui(unsigned a, unsigned b)
{
   if (a > b)
      return a;
   return b;
}

unsigned pow_ui(unsigned a, unsigned n)
{
   if (n == 0) return 1;
   if (n == 1) return a;
   
   unsigned t = n % 2;
   if (t == 0) n /= 2;
   else n = (n-1)/2;
   
   unsigned x = a;
   while(n-- > 1) x *= a;
   
   if (t == 0) return x*x;
   else return x*x*a;
}

unsigned gcd(unsigned a, unsigned b)
{
   while(a) {
      b %= a;
      swap_ui(&a,&b);
   }
   return b;
}

/**************************************
 * MISC INTEGER
 **************************************/

int digits(unsigned n)
{
   if (n>988000000)
      return -1;
   
   unsigned char used[10] = {0};
   used[0] = 1;
   
   unsigned flag = 511;
   unsigned t;
   while (n>0) {
      t = n % 10;
      if (!used[t] && (t-1) >= 0)
         flag = flag ^ (1 << (t-1));
      else
         return -1;
      n /= 10;
      used[t] = 1;
   }
   return flag;
}
int digits_ull(unsigned long long n)
{
   if (n>988000000)
      return -1;
   
   unsigned char used[10] = {0};
   used[0] = 1;
   
   unsigned flag = 511;
   unsigned long long t;
   while (n>0) {
      t = n % 10;
      if (!used[t] && (t-1) >= 0)
         flag = flag ^ (1 << (t-1));
      else
         return -1;
      n /= 10;
      used[t] = 1;
   }
   return flag;
}

/*
unsigned n_digits(unsigned n)
{
   unsigned r = 1;
   while(n>=10) {
      n /= 10;
      r++;
   }
   return r;
}
*/

unsigned nth_digit(unsigned a, unsigned n)
{
   while(n--)
      a /= 10;
   return (a % 10);
}

unsigned long long combine(unsigned a, unsigned b)
{
   unsigned long long c = 1;
   while (c <= b)
      c *= 10;
   return (a * c + b);
}
unsigned combine_uis(unsigned a, unsigned b)
{
   unsigned c = 1;
   while (c <= b)
      c *= 10;
   return (a * c + b);
}

unsigned reverse(unsigned n)
{
   unsigned r = 0;
   while (n > 0) {
      r *= 10;
      r += n % 10;
      n /= 10;
   }
   return r;
}
unsigned long long reverse_ull(unsigned long long n)
{
   unsigned long long r = 0;
   while (n > 0) {
      r *= 10;
      r += n % 10;
      n /= 10;
   }
   return r;
}

unsigned char find_ui_in_array(unsigned *a, unsigned len, unsigned n)
{
   unsigned i;
   for (i=0;i<len;i++) {
      if (a[i]==n)
         return 1;
   }
   return 0;
}

void swap_ui(unsigned *a, unsigned *b)
{
   unsigned tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}

/**************************************
 * MISC CHAR
 **************************************/

void swap_ch(char *a, char *b)
{
   char tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}

unsigned char next_permutation(char *a, unsigned n)
{
   int k = n - 1;
   while (k > 0 && a[k-1] >= a[k] )
      k--;
   
   if (k <= 0)
      return 0;
   
   unsigned l = n - 1;
   while (a[l] <= a[k-1])
      l--;
   
   swap_ch(&a[k-1], &a[l]);
   
   l = n - 1;
   while (k < l) {
      swap_ch(&a[k], &a[l]);
      k++;
      l--;
   }
   return 1;
}