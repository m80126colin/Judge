/**
 *  @judge UVa
 *  @id 11547
 *  @tag Easy, Math, Ad hoc
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		n = 315 * n + 36962;
		if (n < 0) n = -n;
		printf("%d\n", n / 10 % 10);
	}
}