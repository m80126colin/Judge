/**
 *  @judge UVa
 *  @id 10130
 *  @tag DP, 01 Knapsack
 */
#include <iostream>
#include <cstdio>
using namespace std;

#define N 1010
#define G 110
#define W 50
#define INF 1010101010
int n, g, mxg, a[N][2], b[G], dp[W];

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &a[i][0], &a[i][1]);
		scanf("%d", &g);
		mxg = 0;
		for (int j = 0; j < g; j++)
		{
			scanf("%d", &b[j]);
			mxg = max(mxg, b[j]);
		}
		dp[0] = 0;
		for (int i = 1; i <= mxg; i++)
			dp[i] = -INF;
		for (int j = 0; j < n; j++)
			for (int i = mxg; i >= a[j][1]; i--)
				if (dp[i - a[j][1]] >= 0)
					dp[i] = max(dp[i], dp[i - a[j][1]] + a[j][0]);
		for (int i = 1; i <= mxg; i++)
			dp[i] = max(dp[i], dp[i - 1]);
		int ans = 0;
		for (int j = 0; j < g; j++)
			ans += dp[b[j]];
		printf("%d\n", ans);
	}
}