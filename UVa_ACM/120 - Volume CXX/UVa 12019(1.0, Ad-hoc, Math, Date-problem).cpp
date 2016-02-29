#include <iostream>
#include <stdio.h>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char day[7][15] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

int main()
{
	int n, i, m, d;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d%d", &m, &d);
		for (i = 1; i < m; i++) d += month[i - 1];
		puts(day[(d + 5) % 7]);
	}
}