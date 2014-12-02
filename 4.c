/*
 * Project Euler #4 by Josh Oldenburg, 12/1/2014
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

int ispalindrome(uint32_t);

int main() {
	uint32_t largest = 0;

	for (int i = 1e2; i < 1e3; i++) {
		for (int j = 1e2; j < 1e3; j++) {
			uint32_t k = i * j;
			if (k > largest && ispalindrome(k)) {
				largest = k;
				printf("Found palindrome: %u * %u = %u \n", i, j, k);
			}
		}
	}

	printf("%u", largest);
	return 0;
}

int ispalindrome(uint32_t num) {
	int numdigits = floor(log10(num)) + 1;
	char str[numdigits + 1];
	snprintf(str, sizeof(str), "%u", num);

	char reverse[numdigits + 1];
	for (int i = 0, j = numdigits; i < numdigits; i++, j--) {
		reverse[j - 1] = str[i];
	}
	reverse[numdigits] = '\0';

	/* printf("%s => %s - %d\n", str, reverse, numdigits); */
	return (strncmp(str, reverse, numdigits) == 0);
}
