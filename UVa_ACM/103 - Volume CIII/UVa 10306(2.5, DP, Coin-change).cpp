#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXC 50
#define MAXN 310
#define MAX 2100000000
int n, m, s;
int cx[MAXC], cy[MAXC];
int dp[MAXN][MAXN], ans;

int main()
{
	int i, j, k;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d%d", &m, &s);
		for (i = 0; i < m; i++)
			scanf("%d%d", &cx[i], &cy[i]);
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
				dp[i][j] = MAX;
		dp[0][0] = 0;
		for (k = 0; k < m; k++)
			for (i = cx[k]; i < MAXN && i * i <= s * s; i++)
				for (j = cy[k]; j < MAXN && i * i + j * j <= s * s; j++)
					if (dp[i - cx[k]][j - cy[k]] < MAX)
						dp[i][j] = min(dp[i][j], dp[i - cx[k]][j - cy[k]] + 1);
		ans = MAX;
		for (i = 0; i < MAXN && i * i <= s * s; i++)
			for (j = 0; j < MAXN && i * i + j * j <= s * s; j++)
				if (i * i + j * j == s * s)
					ans = min(ans, dp[i][j]);
		if (ans < MAX) printf("%d\n", ans);
		else puts("not possible");
	}
}