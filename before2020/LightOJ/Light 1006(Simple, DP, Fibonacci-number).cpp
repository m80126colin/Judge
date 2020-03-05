#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 10010
#define MOD 10000007
int dp[MAX], n;

int main()
{
	int i, j, t, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < 6; i++)
		{
			scanf("%d", &dp[i]);
			dp[i] %= MOD;
		}
		scanf("%d", &n);
		for (i = 6; i <= n; i++)
		{
			for (j = 1; j <= 6; j++) dp[i] += dp[i - j];
			dp[i] %= MOD;
		}
		printf("Case %d: %d\n", cnt, dp[n]);
	}
}