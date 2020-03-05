#include <iostream>
#include <stdio.h>
#include <string.h>
#define ROW 1<<12
using namespace std;

int t, h, w, c;
long long dp[14][ROW];
int state[ROW], n;
bool ox[ROW];

int istate(int s)
{
	int i;
	for (i = 0; i < w; i++)
	{
		if ( (s & ( 3 << (2 * i) )) >> (2 * i) == 3) return 0;
	}
	for (i = 1; i < w; i++)
	{
		if ( (s & ( 3 << (2 * (i - 1)) )) >> (2 * (i - 1)) == (s & ( 3 << (2 * i) )) >> (2 * i) ) return 0;
	}
	return 1;
}

long long imatch(int p, int s)
{
	int j, i;
	long long d = 0;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < w; i++)
		{
			if ( (s & ( 3 << (2 * i) )) >> (2 * i) == (state[j] & ( 3 << (2 * i) )) >> (2 * i) ) break;
		}
		if (i == w) d += dp[p-1][state[j]];
	}
	return d;
}

int main()
{
	int i, j, row;
	long long ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d", &h, &w, &c);
		memset(ox, 1, sizeof(ox));
		memset(dp, 0, sizeof(dp));
		row = 1 << (2 * w);
		if (c == 1) puts("0");
		else if (c == 2) puts("2");
		else
		{
			n = 0;
			for (j = 0; j < row; j++)
			{
				if (istate(j))
				{
					dp[0][j] = 1;
					state[n++] = j;
				}
				else ox[j] = 0;
			}
			for (i = 1; i < h; i++)
			{
				for (j = 0; j < n; j++)
				{
						dp[i][state[j]] += imatch(i, state[j]);
				}
			}
			ans = 0;
			for (j = 0; j < n; j++)
			{
				ans += dp[h-1][state[j]];
			}
			printf("%lld\n", ans);
		}
	}
}