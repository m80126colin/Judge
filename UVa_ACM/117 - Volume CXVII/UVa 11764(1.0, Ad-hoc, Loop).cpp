#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int t, cnt, n, u, d, i, j, a[50];
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		for (scanf("%d", &n), i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (u = d = 0, n--; n; n--)
		{
			if (a[n + 1] - a[n] > 0) u++;
			else if (a[n + 1] - a[n] < 0) d++;
		}
		printf("Case %d: %d %d\n", cnt, u, d);
	}
}