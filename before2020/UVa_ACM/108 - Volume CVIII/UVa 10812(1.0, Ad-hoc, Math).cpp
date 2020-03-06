/**
 *  @judge UVa
 *  @id 10812
 *  @tag 1.0, Ad-hoc, Math
 */
#include <iostream>
#include <stdio.h>
using namespace std;

int t, a, b;

int sol()
{
	int x, y;
	if (a < 0 || b < 0 || b > a) return 0;
	x = a + b;
	y = a - b;
	if ((x & 1) || (y & 1)) return 0;
	a = x >> 1;
	b = y >> 1;
	if (a < 0 || b < 0) return 0;
	return 1;
}

int main()
{
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &a, &b);
		if (sol()) printf("%d %d\n", a, b);
		else puts("impossible");
	}
}