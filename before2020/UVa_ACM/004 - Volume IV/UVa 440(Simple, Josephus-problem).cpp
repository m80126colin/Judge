/**
 *  @judge UVa
 *  @id 440
 *  @tag Simple, Josephus problem
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int n, m, dp[160];

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		memset(dp, 0, sizeof(dp));
		dp[1] = 0;
		for (m = 2; m; m++)
		{
			for (i = 2; i < n; i++)
			{
				dp[i] = (dp[i - 1] + m) % i;
			}
			dp[n] = (dp[n - 1] + 1) % n;
			if (dp[n] == 1) break;
		}
		printf("%d\n", m);
	}
}