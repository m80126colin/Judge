#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int m, n, M[MAX][MAX], dp[MAX][MAX];
struct rect
{
	int h, w;
	rect(){ h = w = 0; }
	rect(int h, int w): h(h), w(w){}
}stk[MAX];
int sptr;

int main()
{
	int i, j, ans, tmp;
	while (scanf("%d%d", &m, &n), (m || n))
	{
		memset(M, 0, sizeof(M));
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &M[i][j]);
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= m; i++)
			for (j = 1; j <= n; j++)
				if (M[i][j] == 0) dp[i][j] = dp[i - 1][j] + 1;
		ans = 0;
		for (i = 1; i <= m; i++)
		{
			sptr = 0;
			for (j = 1; j <= n; j++)
			{
				tmp = j;
				while (sptr && stk[sptr - 1].h > dp[i][j])
				{
					ans = max(ans, stk[sptr - 1].h * (j - stk[sptr - 1].w));
					tmp = stk[sptr - 1].w;
					sptr--;
				}
				if (sptr == 0 || stk[sptr - 1].h < dp[i][j])
				{
					stk[sptr] = rect(dp[i][j], tmp);
					sptr++;
				}
			}
			while (sptr)
			{
				ans = max(ans, stk[sptr - 1].h * (j - stk[sptr - 1].w));
				sptr--;
			}
		}
		printf("%d\n", ans);
	}
}