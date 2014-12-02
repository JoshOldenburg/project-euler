/*
 * Project Euler #5 by Josh Oldenburg, 12/1/2014
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int divisible(uint32_t);

int main() {
	uint32_t x = 20;

	while (x++) {
		if (divisible(x)) {
			printf("%u", x);
			return 0;
		}
	}

	return 0;
}

int divisible(uint32_t num) {
	for (int divisor = 2; divisor <= 20; divisor++) {
		if (num % divisor != 0) return 0;
	}
	return 1;
}
