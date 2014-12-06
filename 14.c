/*
 * Project Euler #14 by Josh Oldenburg, 12/6/2014
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 *
 * 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int collatzlength(int);

int main() {
	int max = 0;
	int length = 0;

	for (int i = 2; i <= 1e6; i++) {
		int collatz = collatzlength(i);
		if (collatz > length) {
			max = i;
			length = collatz;
			printf("i = %u, collatzlength = %u, max = %u, maxlength = %u\n", i, collatz, max, length);
		}
	}

	printf("%u", max);
	return 0;
}

int collatzlength(int num) {
	uint64_t current = num;
	int length = 0;
	while (current > 1) {
		if (current % 2 == 0) current /= 2;
		else current = (3 * current + 1);
		length++;
	}
	return length;
}
