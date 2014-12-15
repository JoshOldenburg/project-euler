/*
 * Project Euler #33 by Josh Oldenburg, 12/14/2014
 *
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.
 *
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples.
 *
 * There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.
 *
 * If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#define EQUALSACCURACY(value1, value2, accuracy) (fabs((double)(value1) - (double)(value2)) < (accuracy))

int main() {
	unsigned int totalnum = 1;
	unsigned int totaldenom = 1;

	for (unsigned int denominator = 10; denominator < 100; denominator++) {
		for (unsigned int numerator = 10; numerator < denominator; numerator++) {
			char num[3];
			char denom[3];
			snprintf(num, sizeof(num), "%u", numerator);
			snprintf(denom, sizeof(denom), "%u", denominator);

			if (num[0] == denom[0] || num[1] == denom[1]) continue;
			if (num[0] == denom[1] || num[1] == denom[0]) {
				unsigned int newnum = ((num[0] == denom[1] ? num[1] : num[0]) - '0');
				unsigned int newdenom = ((num[0] == denom[1] ? denom[0] : denom[1]) - '0');

				if (EQUALSACCURACY(((double)numerator)/((double)denominator), ((double)newnum)/((double)newdenom), 1e-7)) {
					printf("Found match: %u/%u == %u/%u == %f\n", numerator, denominator, newnum, newdenom, (double)newnum/newdenom);

					totalnum *= newnum;
					totaldenom *= newdenom;
				}
			}
		}
	}

	printf("%u/%u", totalnum, totaldenom);
	return 0;
}
