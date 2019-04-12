#include <stdio.h>
#include <math.h>
#include <time.h>

int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int dayofweek(int year, int month, int day)
{
	if (month== 1 || month == 2) {
		year--;
		month += 12;
	}
	return ((year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7);
}

int main(void)
{
	int y, m;

	putchar('\n');
	return 0;
}

