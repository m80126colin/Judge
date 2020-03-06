/**
 *  @judge ZeroJudge
 *  @id c069
 *  @tag Simple, Ad-hoc, Date problem
 */
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define IsLeap(x) ((x <= 1752)? (x % 4 == 0): ((x % 100 && x % 4 == 0) || x % 400 == 0))
int Month[13] = {
		0,
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};
#define Day(y, x) (30 + (y > 7) ^ (x & 1))

int IsSyntaxValid(int y, int m, int d)
{
	if (y < 0 || m < 0 || m > 12 || d < 0) return 0;
	return d <= Month[m] + (m == 2) * IsLeap(y);
}

int ValidInAmerica(int y, int m, int d)
{
	if (y != 1752 || (y == 1752 && m != 9)) return 1;
	return d <= 2 || d >= 14;
}

int main()
{
	int yy, mm, dd;
	int day;
	
	string Year[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	string Seven[7] = {
		"Sunday",
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday"
	};
	int i;
	while (scanf("%d%d%d", &mm, &dd, &yy), (yy || mm || dd))
	{
		day = 5;
		if (IsSyntaxValid(yy, mm, dd) && ValidInAmerica(yy, mm, dd))
		{
			for (i = 1; i < yy; i++)
				day += 365 + IsLeap(i);
			if (yy <= 0)
			{
				for (i = 0; i >= yy; i--)
					day -= (365 + IsLeap(i));
			}
			for (i = 1; i < mm; i++)
				day += Month[i] + (i == 2) * IsLeap(yy);
			day += dd;
			if (yy > 1752 || (yy == 1752 && (mm > 9 || (mm == 9 && dd >= 14))))
				day += 3;
			day = ((day % 7) + 7) % 7;
			printf("%s %d, %d is a %s\n", Year[mm - 1].c_str(), dd, yy, Seven[day].c_str());
		}
		else printf("%d/%d/%d is an invalid date.\n", mm, dd, yy);
	}
}