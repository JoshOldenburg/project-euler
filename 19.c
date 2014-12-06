/*
 * Project Euler #19 by Josh Oldenburg, 12/6/2014
 *
 * You are given the following information, but you may prefer to do some research for yourself.
 *
 * 1 Jan 1900 was a Monday.
 * Thirty days has September,
 * April, June and November.
 * All the rest have thirty-one,
 * Saving February alone,
 * Which has twenty-eight, rain or shine.
 * And on leap years, twenty-nine.
 * A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 *
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

unsigned int dayofweek(int month, int day, int year);
int wikidow(int month, int day, int year);

int main() {
	unsigned int num = 0;

	for (int year = 1901; year <= 2000; year++) {
		for (int month = 1; month <= 12; month++) {
			if (wikidow(month, 1, year) == 0) num++;
		}
	}

	/* num = wikidow(1, 1, 1900); */
	printf("%d", num);
	return 0;
}

int months[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
int centuries[] = {6, 4, 2, 0};
unsigned int dayofweek(int month, int day, int year) {
	unsigned int dow = (unsigned int)(day + months[month] + (year % 100) + floor(year / 4) + centuries[((unsigned int)floor(year / 100) % 4u)]) % 7u;
	if (month < 3 && (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {
		if (dow == 0) dow = 6;
		else dow--;
	}
	return dow;
}

int wikidow(int m, int d, int y) { // https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= (m < 3) ? 1 : 0;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
