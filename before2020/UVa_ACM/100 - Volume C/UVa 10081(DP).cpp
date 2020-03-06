/**
 *  @judge UVa
 *  @id 10081
 *  @tag DP
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 110
int k, n;
double dp[MAX][MAX];

int main()
{
	int i, j;
	while (scanf("%d%d", &k, &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		for (i = 0; i <= k; i++)
			dp[i][1] = 1;
		for (j = 2; j <= n; j++)
		{
			for (i = 0; i <= k; i++)
			{
				if (i > 0) dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i][j - 1] + dp[i + 1][j - 1];
			}
		}
		double sum = 0;
		for (i = 0; i <= k; i++)
			sum += dp[i][n];
		printf("%.5lf\n", sum * 100.0 / pow(k + 1.0, n + 0.0));
	}
}