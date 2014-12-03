/*
 * Project Euler #3 by Josh Oldenburg, 12/1/2014
 *
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int isprime(uint64_t);
int wikiisprime(unsigned long);

int main() {
	uint64_t factor = 0;
	uint64_t number = 600851475143;

	for (uint64_t i = 1; i < number; i++) { // While between the square root and the number,
		if (number % i == 0) printf("New factor: %llu\n", i);
		if (number % i == 0 && isprime(i)) { // if it is a factor and prime, set the factor.
			factor = i;
			printf("  is prime: %llu\n", factor);
		}
	}

	printf("%llu", factor);
	return 0;
}

int isprime(uint64_t num) {
	if (num == 1) return 0;
	else if (num > 1 && num <= 3) return 1;
	else if (num % 2 == 0 || num % 3 == 0) return 0;

	// 1: don't bother with sqrt; 0: only compare up to sqrt
	// 0 is far, far faster
	uint64_t numsqrt = 1 ? num : ceil(sqrt(num));

	for (uint64_t i = 4; i <= numsqrt; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}

int wikiisprime(unsigned long n) { // https://en.wikipedia.org/wiki/Primality_test
	if (n <= 3) {
		return n > 1;
	} else if (n % 2 == 0 || n % 3 == 0) {
		return 0;
	} else {
		for (unsigned short i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) {
				return 0;
			}
		}
		return 1;
	}
}
