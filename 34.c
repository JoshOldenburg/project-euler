/*
 * Project Euler #34 by Josh Oldenburg, 12/15/2014
 *
 * 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
 *
 * Find the sum of all numbers which are equal to the sum of the factorial of their digits.
 *
 * Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

const uint64_t factorial(unsigned int);

int main() {
	uint64_t sum = 0;

	for (unsigned int x = 10; x < 1000000; x++) { // It'd be nice if they expliticly gave an upper bound
		int numdigits = floor(log10(x)) + 1;
		char str[numdigits + 1];
		snprintf(str, sizeof(str), "%u", x);
		int length = strlen(str);

		uint64_t factorialsum = 0;

		for (int i = 0; i < length; i++) {
			char y = str[i];
			unsigned int num = (y - '0');
			factorialsum += factorial(num);
		}

		if (factorialsum == x) {
			printf("Found match: %u\n", x);
			sum += x;
		}
	}

	printf("%llu", sum);
	return 0;
}

const uint64_t factorial(unsigned int input) {
	double current = 1;
	for (int x = input; x > 1; x--) current *= x;
	return current;
}
