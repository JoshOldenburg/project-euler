/*
 * Project Euler #10 by Josh Oldenburg, 12/1/2014
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int isprime(uint64_t);

int main() {
	uint64_t sum = 2;

	for (int x = 3; x < 2e6; x += 2) if (isprime(x)) sum += x;

	printf("%llu", sum);
	return 0;
}

int isprime(uint64_t num) {
	if (num == 1) return 0;
	else if (num > 1 && num <= 3) return 1;
	else if (num % 2 == 0 || num % 3 == 0) return 0;

	// 1: don't bother with sqrt; 0: only compare up to sqrt
	// 0 is far, far faster
	uint64_t numsqrt = 0 ? num : ceil(sqrt(num));

	for (uint64_t i = 4; i <= numsqrt; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}
