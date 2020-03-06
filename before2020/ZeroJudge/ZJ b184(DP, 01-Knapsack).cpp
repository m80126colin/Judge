/**
 *  @judge ZeroJudge
 *  @id b184
 *  @tag DP, 01 Knapsack
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 1010
#define VMAX 101
int dp[VMAX], v, c;

int main()
{
	int n, i, j, mx;
	while (scanf("%d", &n) != EOF)
	{
		mx = 0;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &v, &c);
			for (j = VMAX; j; j--)
				if (dp[j - 1] && j + v - 1 < VMAX)
				{
					dp[j + v - 1] = max(dp[j + v - 1], dp[j - 1] + c);
					mx = max(mx, dp[j - 1] + c);
				}
		}
		printf("%d\n", mx - 1);
	}
}