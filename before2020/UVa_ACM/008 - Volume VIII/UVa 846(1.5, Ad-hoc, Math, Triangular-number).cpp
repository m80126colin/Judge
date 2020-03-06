/**
 *  @judge UVa
 *  @id 846
 *  @tag 1.5, Ad hoc, Math, Triangular number
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int sol(int n)
{
	int m = (-1.0 + sqrt(1.0 + 4.0 * n)) / 2.0, r = n - m * (m + 1);
	return 2 * m + (r > 0) + (r > m + 1);
}

int main()
{
	int x, y, t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", sol(y - x));
	}
}