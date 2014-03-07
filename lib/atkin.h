#include <stdlib.h>
#include <stdint.h>
#include <math.h>

inline void set_bit(uint32_t *a, uint_fast64_t n);
inline void clr_bit(uint32_t *a, uint_fast64_t n);
inline int is_bit_set(uint32_t *a, uint_fast64_t n);

void sieve_of_atkin(uint_fast64_t *a, uint_fast64_t limit);
void sieve_of_atkin_b(uint32_t *is_prime_bit, uint_fast64_t limit);