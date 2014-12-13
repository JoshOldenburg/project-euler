/*
 * Project Euler #53 by Josh Oldenburg, 12/12/2014
 *
 * There are exactly ten ways of selecting three from five, 12345:
 *
 * 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345
 *
 * In combinatorics, we use the notation, 5C3 = 10.
 *
 * In general,
 *
 * nCr =
 * n!
 * r!(n−r)!
 * ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
 * It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.
 *
 * How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

const double factorial(unsigned int);
double nCr(unsigned int, unsigned int);

int main() {
	uint32_t num = 0;

	for (unsigned int n = 1; n <= 100; n++) {
		for (unsigned int r = 1; r <= n; r++) {
			if (nCr(n, r) > 1000000) {
				num++;
				printf("Match: %uC%u\n", n, r);
			}
		}
	}

	printf("%u", num);
	return 0;
}

const double factorial(unsigned int input) {
	double current = 1;
	for (int x = input; x > 1; x--) current *= x;
	return current;
}

double nCr(unsigned int n, unsigned int r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}
