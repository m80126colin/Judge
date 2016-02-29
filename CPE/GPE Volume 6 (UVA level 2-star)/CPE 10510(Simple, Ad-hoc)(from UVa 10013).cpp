#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[1000100], b;

int main()
{
	int t, n, i, c;
	for (cin >> t; t; t--)
	{
		for (cin >> n, i = 1; i <= n; i++)
		{
			cin >> a[i] >> b;
			a[i] += b;
		}
		c = 0;
		for (i = n; i; i--)
		{
			a[i] += c;
			c = a[i] / 10;
			a[i] %= 10;
		}
		if (c) printf("%d", c);
		for (i = 1; i <= n; i++) putchar('0' + a[i]);
		puts("");
		if (t > 1) puts("");
	}
}