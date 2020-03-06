/**
 *  @judge UVa
 *  @id 108
 *  @tag 2.5, DP, Max consecutive subsequence 2D
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int n, M[MAX][MAX], dp[MAX][MAX];

int main()
{
	int i, j, x, y, ans;
	while (scanf("%d", &n) != EOF)
	{
		memset(M, 0, sizeof(M));
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				scanf("%d", &M[i][j]);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				dp[i][j] = M[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
		ans = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (x = i + 1; x <= n; x++)
					for (y = j + 1; y <= n; y++)
						ans = max(ans, dp[x][y] - dp[x][j] - dp[i][y] + dp[i][j]);
		printf("%d\n", ans);
	}
}