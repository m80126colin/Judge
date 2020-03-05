#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define N 16
#define M 110
int n, ans;
int dp[M][M][M];
char str[N][M];
int len[N];

int input()
{
	if (scanf("%d", &n) == EOF)
		return EOF;
	for (int i = 0; i < n; i++)
	{
		if (scanf("%s", str[i] + 1) == EOF)
			return EOF;
		len[i] = strlen(str[i] + 1);
	}
	return 0;
}

int LCS(int x, int y, int z)
{
	int i, j, k;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= len[x]; i++)
		for (j = 1; j <= len[y]; j++)
			for (k = 1; k <= len[z]; k++)
			{
				if (str[x][i] == str[y][j] && str[y][j] == str[z][k])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
	return dp[len[x]][len[y]][len[z]];
}

int sol()
{
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				ans = max(ans, LCS(i, j, k));
	return ans;
}

int main()
{
	while (input() != EOF)
		printf("%d\n", sol());
}