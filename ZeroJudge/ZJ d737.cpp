#include <stdio.h>
#include <iostream>
using namespace std;

int ub[27], lb[27];
int dp[27][27][352], ans[27][352];

int main()
{
	int l, s, i, j, k, ii, ctr;
	memset(ub, 0, sizeof(ub));
	memset(lb, 0, sizeof(lb));
	memset(dp, 0, sizeof(dp));
	memset(ans, 0, sizeof(ans));
	for (i = 1; i <= 26; i++)
	{
		ub[i] = ub[i - 1] + 27 - i;
		lb[i] = lb[i - 1] + i;
	}
	for (k = 1; k <= 26; k++) dp[1][k][k] = ans[1][k] = 1;
	for (i = 1; i < 26; i++)
	{
		for (j = 1; j <= 26; j++)
		{
			for (k = 1; k <= 351; k++)
			{
				for (ii = j + 1; ii <= 26; ii++)
				{
					if (k + ii > 351) break;
					dp[i + 1][ii][k + ii] += dp[i][j][k];
					ans[i + 1][k + ii] += dp[i][j][k];
				}
				
			}
		}
	}
	ctr = 1;
	while (scanf("%d%d", &l, &s) && (l || s))
	{
		printf("Case %d: ", ctr++);
		if (l > 26 || s > 351) puts("0");
		else printf("%d\n", ans[l][s]);
	}
}