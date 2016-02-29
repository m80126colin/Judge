#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, x[1010], y[1010];

inline void getd(int &d)
{
	bool ox = 0;
	char ch;
	while (!isdigit(ch = getchar()))
	{
		if (ch == '-')
		{
			ch = '0';
			ox = 1;
			break;
		}
	}
	d = 0;
	do{
		d = d * 10 + ch - '0';
	}while (isdigit(ch = getchar()));
	if (ox) d = -d;
}

int main()
{
	int t, i, sum, way;
	for (getd(t); t; t--)
	{
		getd(n);
		for (i = 0; i < n; i++)
		{
			getd(x[i]);
			getd(y[i]);
		}
		sort(x, x+n);
		sort(y, y+n);
		sum = 0;
		for (i = 0; i < n; i++)
		{
			sum += abs(x[i] - x[n/2]) + abs(y[i] - y[n/2]);
		}
		if (n & 1) way = 1;
		else
		{
			way = (x[n/2] - x[n/2-1] + 1) * (y[n/2] - y[n/2-1] + 1);
		}
		printf("%d %d\n", sum, way);
	}
}