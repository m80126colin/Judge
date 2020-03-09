/**
 *  @judge ZeroJudge
 *  @id a261
 *  @source UVa 10934
 */
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	long long n, dp[110][70];
	int k, t;
	memset(dp, 0, sizeof(dp));
	for (k = 1; k <= 100; k++)
	{
		for (t = 1; t < 64; t++)
		{
			dp[k][t] = dp[k][t - 1] + 1 + dp[k - 1][t - 1];
		}
	}
	while (scanf("%d%lld", &k, &n) && k)
	{
		for (t = 1; t < 64; t++)
		{
			if (dp[k][t] >= n) break;
		}
		if (t < 64) printf("%d\n", t);
		else puts("More than 63 trials needed.");
	}
}