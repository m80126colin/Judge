#include <stdio.h>
#include <string.h>
#include <iostream>
#define MAX 2010
#define mMAX 1000000000
using namespace std;

bool ox[MAX][MAX];
int dp[MAX][MAX];

void update(int i, int j, int s)
{
	if (j + s >= 0 || j + s < MAX)
	{
		dp[i + 1][j + s] += dp[i][j];
		if (ox[i][j]) ox[i + 1][j + s] = 1;
	}
	if (dp[i + 1][j + s] / mMAX)
	{
		ox[i + 1][j + s] = 1;
		dp[i + 1][j + s] %= mMAX;
	}
	return;
}

int main()
{
	int i, j, ctr;
	int t, n;
	char rod[MAX];
	
	for (scanf("%d", &t), ctr = 1; ctr <= t; ctr++)
	{
		scanf("%d%s", &n, rod);
		memset(dp, 0, sizeof(dp));
		memset(ox, 0, sizeof(ox));
		dp[0][0] = 1;
		for (i = 0; i < n; i++)
		{
			for (j = MAX - 1; j >= 0; j--)
			{
				if (!dp[i][j] && !ox[i][j]) continue;
				if (rod[i] == 'R')
				{
					update(i, j, 1);
					update(i, j, -1);
				}
				else
				{
					update(i, j, (rod[i] == 'F') - (rod[i] == 'B'));
				}
			}
		}
		printf("Case %d: ", ctr);
		if (ox[n][0]) printf("%09d\n", dp[n][0] % mMAX);
		else printf("%d\n", dp[n][0]);
	}
}