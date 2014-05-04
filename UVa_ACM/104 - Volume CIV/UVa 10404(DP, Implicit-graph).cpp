#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main()
{
	int n, m, move[15], i, j;
	static int dp[1000010];
	while (scanf("%d", &n) != EOF)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &move[i]);
			dp[move[i]] = 1;
		}
		for (i = 2; i <= n; i++)
		{
			if (!dp[i])
			{
				for (j = 0; j < m; j++)
				{
					if (move[j] <= i && (!dp[i - move[j]]) )
					{
						dp[i] = 1;
						break;
					}
				}
			}
		}
		if (dp[n]) puts("Stan wins");
		else puts("Ollie wins");
	}
}