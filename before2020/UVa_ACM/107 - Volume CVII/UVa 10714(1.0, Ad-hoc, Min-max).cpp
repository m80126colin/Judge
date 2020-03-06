/**
 *  @judge UVa
 *  @id 10714
 *  @tag 1.0, Ad-hoc, Min max
 */
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	int t, L, n, mx, mn, tmp;
	for (scanf("%d", &t); t; t--)
	{
		mx = mn = 0;
		for (scanf("%d%d", &L, &n); n; n--)
		{
			scanf("%d", &tmp);
			mx = max(mx, max(tmp, L - tmp));
			mn = max(mn, min(tmp, L - tmp));
		}
		printf("%d %d\n", mn, mx);
	}
}