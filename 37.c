/*
 * Project Euler #37 by Josh Oldenburg, 12/22/2014
 *
 * The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.
 *
 * Find the sum of the only eleven primes that are both truncatable from left to right and right to left.
 *
 * NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int isprime(uint64_t);

int main() {
	uint32_t sum = 0;

	for (unsigned int x = 11, i = 0; i < 11; x += 2) {
		int xmod10 = x % 10;
		if (xmod10 == 1 || xmod10 == 9 || !isprime(x)) continue;

		int numdigits = floor(log10(x)) + 1;
		char str[numdigits + 1];
		snprintf(str, sizeof(str), "%u", x);
		int length = strlen(str);

		/* printf(" Testing number: %u / %s (%d/%d)\n", x, str, numdigits, length); */

		int allprimes = 1;
		for (int j = 0; j < (length - 0); j++) { // Removing LTR
			char *shortstr = (str + j);
			/* printf("  Testing primality: %u -> %s\n", x, shortstr); */
			if (!isprime(strtol(shortstr, NULL, 10))) {
				allprimes = 0;
				break;
			}
		}
		for (int j = length; j > 0; j--) { // Removing RTL
			str[j] = '\0';
			/* printf("  Testing primality: %u -> %s\n", x, str); */
			if (!isprime(strtol(str, NULL, 10))) {
				allprimes = 0;
				break;
			}
		}

		if (allprimes) {
			printf("Found match: %u\n", x);
			sum += x;
			i++;
		}
	}

	printf("%u", sum);
	return 0;
}

int isprime(uint64_t num) {
	if (num == 1) return 0;
	else if (num > 1 && num <= 3) return 1;
	else if (num % 2 == 0 || num % 3 == 0) return 0;

	// 1: don't bother with sqrt; 0: only compare up to sqrt
	uint64_t numsqrt = 0 ? num : ceil(sqrt(num));

	for (uint64_t i = 4; i <= numsqrt; i++) {
		if (num % i == 0) return 0;
	}

	return 1;
}
