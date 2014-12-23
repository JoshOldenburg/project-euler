/*
 * Project Euler #30 by Josh Oldenburg, 12/22/2014
 *
 * Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:
 *
 * 1634 = 1^4 + 6^4 + 3^4 + 4^4
 * 8208 = 8^4 + 2^4 + 0^4 + 8^4
 * 9474 = 9^4 + 4^4 + 7^4 + 4^4
 * As 1 = 1^4 is not a sum it is not included.
 *
 * The sum of these numbers is 1634 + 8208 + 9474 = 19316.
 *
 * Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int main() {
	uint64_t total = 0;

	for (uint64_t x = 10; x < 1000000; x++) {
		uint64_t y = x;
		uint64_t sum = 0;
		do {
			int digit = y % 10;
			y /= 10;

			uint64_t x5 = 1;
			for (int i = 5; i > 0; i--) x5 *= digit;

			sum += x5;
			if (sum > x) break;
		} while (y > 0);

		if (x == sum) {
			printf("  Found match: %llu\n", x);
			total += x;
		}
	}

	printf("%llu", total);
	return 0;
}
