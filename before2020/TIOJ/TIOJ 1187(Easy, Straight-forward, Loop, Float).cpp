/**
 *  @judge TIOJ
 *  @id 1187
 *  @tag Easy, Straight forward, Loop, Float
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int n, mx, mn, tmp, ttl;

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		scanf("%d", &tmp);
		mx = mn = ttl = tmp;
		for (i = 1; i < n; i++)
		{
			scanf("%d", &tmp);
			if (tmp > mx) mx = tmp;
			if (tmp < mn) mn = tmp;
			ttl += tmp;
		}
		printf("%.02lf\n", (double) (ttl - mx - mn) / (n - 2) + 1e-9);
	}
}