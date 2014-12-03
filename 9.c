/*
 * Project Euler #9 by Josh Oldenburg, 12/1/2014
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 *
 * a^2 + b^2 = c^2
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int istriple(int, int, int);

int main() {
	for (int a = 0; a < 500; a++) {
		for (int b = 0; b < 500; b++) {
			for (int c = 0; c < 500; c++) {
				if (istriple(a, b, c) && ((a + b + c) == 1000)) {
					printf("%u (%u, %u, %u)", a * b * c, a, b, c);
					return 0;
				}
			}
		}
	}

	return 0;
}

int istriple(int a, int b, int c) {
	return (a * a + b * b) == (c * c);
}
