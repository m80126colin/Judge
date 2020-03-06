/**
 *  @judge UVa
 *  @id 11081
 *  @tag 3.0, DP, String DP, Modular arithmatic
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 70
#define MOD 10007
char str1[MAX], str2[MAX], str3[MAX];
int len1, len2, len3;
int dp[MAX][MAX][MAX], dp1[MAX][MAX][MAX], dp2[MAX][MAX][MAX];

int main()
{
	int t, i, j, k;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s%s%s", str1 + 1, str2 + 1, str3 + 1);
		len1 = strlen(str1 + 1);
		len2 = strlen(str2 + 1);
		len3 = strlen(str3 + 1);
		memset(dp, 0, sizeof(dp));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		for (i = 0; i <= len1; i++)
			for (j = 0; j <= len2; j++)
				dp[0][i][j] = dp1[0][i][j] = dp2[0][i][j] = 1;
		for (k = 1; k <= len3; k++)
			for (i = 0; i <= len1; i++)
				for (j = 0; j <= len2; j++)
				{
					if (i)
					{
						dp1[k][i][j] = dp1[k][i - 1][j];
						if (str1[i] == str3[k])
							dp1[k][i][j] += dp[k - 1][i - 1][j];
						dp1[k][i][j] %= MOD;
					}
					if (j)
					{
						dp2[k][i][j] = dp2[k][i][j - 1];
						if (str2[j] == str3[k])
							dp2[k][i][j] += dp[k - 1][i][j - 1];
						dp2[k][i][j] %= MOD;
					}
					dp[k][i][j] = (dp1[k][i][j] + dp2[k][i][j]) % MOD;
				}
		printf("%d\n", dp[len1][len2][len3]);
	}
}