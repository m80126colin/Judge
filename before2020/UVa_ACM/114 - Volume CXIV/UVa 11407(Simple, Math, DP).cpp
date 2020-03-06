/**
 *  @judge UVa
 *  @id 11407
 *  @tag Simple, Math, DP
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	int i, t, n;
	int a[10010], dp[10010];
	memset(a, 0, sizeof(a));
	for (i = 1; i <= 100; i++) a[i * i] = 1;
	for (i = 1; i <= 10000; i++)
	{
		if (a[i]) dp[i] = 1;
		else
		{
			dp[i] = 100000;
			for (n = sqrt(i * 1.0); n; n--)
				dp[i] = min(dp[i], dp[i - n * n] + 1);
		}
	}
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
}