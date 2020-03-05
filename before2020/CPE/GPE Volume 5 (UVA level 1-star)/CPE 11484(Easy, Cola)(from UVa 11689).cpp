#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n, e, f, l;
	int d, c;
	for (cin >> n; n; n--)
	{
		cin >> e >> f >> l;
		e += f;
		c = d = 0;
		while (e + c >= l)
		{
			e += c;
			c = e % l;
			e /= l;
			d += e;
		}
		printf("%d\n", d);
	}
}