/*
 * Project Euler #6 by Josh Oldenburg, 12/1/2014
 *
 * The sum of the squares of the first ten natural numbers is,
 *
 * 1^2 + 2^2 + ... + 10^2 = 385
 * The square of the sum of the first ten natural numbers is,
 *
 * (1 + 2 + ... + 10)^2 = 55^2 = 3025
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int main() {
	uint32_t sumofsquares = 0;
	uint32_t squareofsum = 0;

	for (int x = 0; x <= 100; x++) sumofsquares += (x * x);
	for (int x = 0; x <= 100; x++) squareofsum += x;
	squareofsum = squareofsum * squareofsum;

	uint32_t num = squareofsum - sumofsquares;

	printf("%u", num);
	return 0;
}
