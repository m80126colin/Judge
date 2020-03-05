#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MOD 5
#define MAXC 6
#define MAXN 50010 / MOD
#define INF 2100000000
int c[MAXC], co, w[MAXC] = {5 / MOD, 10 / MOD, 20 / MOD, 50 / MOD, 100 / MOD, 200 / MOD};
int mn, dp[MAXN];

int input()
{
	int i, t1, t2;
	for (i = 0; i < MAXC; i++)
		scanf("%d", &c[i]);
	if (c[0] == 0 && c[1] == 0 && c[2] == 0 && c[3] == 0 && c[4] == 0 && c[5] == 0)
		return EOF;
	scanf("%d.%d", &t1, &t2);
	co = t1 * 100 + t2;
	return 0;
}

int GreedyCoin(int x)
{
	int i, ans = 0;
	for (i = MAXC - 1; i >= 0; i--)
		if (x / w[i])
		{
			ans += x / w[i];
			x %= w[i];
		}
		return ans;
}

void sol()
{
	int i, j, k;
	for (i = 0; i < MAXN; i++)
		dp[i] = INF;
	dp[0] = 0;
	for (j = 0; j < MAXC; j++)
	{
		if (c[j])
		{
			for (i = MAXN - 1; i >= 0; i--)
			{
				if (dp[i] < INF)
				{
					for (k = 1; k <= c[j]; k++)
					{
						if (i + k * w[j] < MAXN)
							dp[i + k * w[j]] = min(dp[i + k * w[j]], dp[i] + k);
					}
				}
			}
		}
	}
	for (i = MAXN - 1; i >= co; i--)
	{
		if (dp[i] < INF) mn = min(mn, dp[i] + GreedyCoin(i - co));
	}
	return ;
}

int main()
{
	while (input() != EOF)
	{
		co /= MOD;
		mn = INF;
		sol();
		printf("%3d\n", mn);
	}
}