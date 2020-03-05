#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int n, k;
int dp[100010];

int main()
{
	int t, ctr, i;
	for (scanf("%d", &t), ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d%d", &n, &k);
		memset(dp, 0, sizeof(dp));
		dp[1] = 0;
		for (i = 2; i <= n; i++)
		{
			dp[i] = (dp[i - 1] + k) % i;
		}
		printf("Case %d: %d\n", ctr, dp[n] + 1);
	}
}