/*
 * Project Euler #7 by Josh Oldenburg, 12/1/2014
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int isprime(uint64_t);

int main() {
	uint32_t num = 1; // number of prime
	uint32_t x = 3; // prime

	for (x = 3; num < 10001; x += 2) {
		if (isprime(x)) {
			num++;
			/* if (num > 9990) printf("Found prime #%u: %u\n", num, x); */
		}
	}

	printf("%u", x - 2);
	return 0;
}

int isprime(uint64_t num) {
	if (num == 1) return 0;
	else if (num > 1 && num <= 3) return 1;
	else if (num % 2 == 0 || num % 3 == 0) return 0;

	// 1: don't bother with sqrt; 0: only compare up to sqrt
	// 1 is far, far faster
	uint64_t numsqrt = 1 ? num : ceil(sqrt(num));

	for (uint64_t i = 4; i < numsqrt; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

