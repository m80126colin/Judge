#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long myabs(long long x)
{
	if (x < 0) return -x;
	return x;
}

long long pos(long long x, long long y)
{
	long long n = x + y + 1;
	return n * (n - 1) / 2 + n - y;
}

int main()
{
	long long n, x1, y1, x2, y2, ctr;
	for (cin >> n, ctr = 1; ctr <= n; ctr++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		printf("Case %lld: %lld\n", ctr, myabs(pos(x2, y2) - pos(x1, y1)));
	}
}