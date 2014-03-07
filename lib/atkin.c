#include "atkin.h"

inline void set_bit(uint32_t *a, uint_fast64_t n)
{
   a[n/32] |= 1 << (n % 32);
}
inline void clr_bit(uint32_t *a, uint_fast64_t n)
{
   a[n/32] &= ~(1 << (n % 32));
}
inline int is_bit_set(uint32_t *a, uint_fast64_t n)
{
   return (a[n/32] & (1 << (n % 32)));
}

void sieve_of_atkin(uint_fast64_t *a, uint_fast64_t limit)
{
   a[0] = 2; a[1] = 3;
   uint32_t index = 2;
   
   uint32_t *is_prime_bit = calloc(limit/32+1, sizeof(uint32_t));
   uint_fast64_t i,x,y;
   
   uint_fast64_t root = sqrt(limit);
   uint_fast64_t rootxa = sqrt(limit/3);
   uint_fast64_t rootxb = sqrt(limit/4);
   for(x = 1; x <= root; x++) {
      uint_fast64_t xa = 3*x*x, xb = 0;
      uint_fast64_t roota = 0, rootb = 0;
      
      if (x <= rootxa)
         roota = sqrt(limit - xa);
      if (x <= rootxb) {
         xb = 4*x*x;
         rootb = sqrt(limit - xb);
      }
      
      for(y = 1; y <= root; y++) {
         if (y > roota && x < y)
            break;
         
         uint_fast64_t n;
         if (y <= rootb) {
            n = xb + y*y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)) {
               set_bit(is_prime_bit,n);
            }
         }
         
         if (y <= roota) {
            n = xa + y*y;
            if (n <= limit && n % 12 == 7)
               set_bit(is_prime_bit,n);
         }
         
         if (x > y) {
            n = xa - y*y;
            if (n <= limit && n % 12 == 11)
               set_bit(is_prime_bit,n);
         }
      }
   }
   
   for(x = 5; x <= root; x += 2) {
      if (is_bit_set(is_prime_bit,x)) {
         uint_fast64_t lim = (limit/x*x);
         for(y = x*x; y < lim; y += x)
            clr_bit(is_prime_bit,y);
      }
   }
   
   for(x = 5; x <= limit; x += 2) {
      if (is_bit_set(is_prime_bit,x))
         a[index++] = x;
   }
   free(is_prime_bit);
}

void sieve_of_atkin_b(uint32_t *is_prime_bit, uint_fast64_t limit)
{
   uint_fast64_t i,x,y;
   
   uint_fast64_t root = sqrt(limit);
   uint_fast64_t rootxa = sqrt(limit/3);
   uint_fast64_t rootxb = sqrt(limit/4);
   for(x = 1; x <= root; x++) {
      uint_fast64_t xa = 3*x*x, xb = 0;
      uint_fast64_t roota = 0, rootb = 0;
      
      if (x <= rootxa)
         roota = sqrt(limit - xa);
      if (x <= rootxb) {
         xb = 4*x*x;
         rootb = sqrt(limit - xb);
      }
      
      for(y = 1; y <= root; y++) {
         if (y > roota && x < y)
            break;
         
         uint_fast64_t n;
         if (y <= rootb) {
            n = xb + y*y;
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
               set_bit(is_prime_bit,n);
         }
         
         if (y <= roota) {
            n = xa + y*y;
            if (n <= limit && n % 12 == 7)
               set_bit(is_prime_bit,n);
         }
         
         if (x > y) {
            n = xa - y*y;
            if (n <= limit && n % 12 == 11)
               set_bit(is_prime_bit,n);
         }
      }
   }
   
   for(x = 5; x <= root; x += 2) {
      if (is_bit_set(is_prime_bit,x)) {
         uint_fast64_t lim = (limit/x*x);
         for(y = x*x; y < lim; y += x)
            clr_bit(is_prime_bit,y);
      }
   }
}