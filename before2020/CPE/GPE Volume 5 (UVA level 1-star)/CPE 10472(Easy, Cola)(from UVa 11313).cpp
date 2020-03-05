#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, m, t, c, d;
	for (cin >> t; t; t--)
	{
		cin >> n >> m;
		c = d = 0;
		while (n+c > m)
		{
			n += c;
			c = n % m;
			n /= m;
			d += n;
		}
		if (n + c == m) printf("%d\n", d + 1);
		else puts("cannot do this");
	}
}