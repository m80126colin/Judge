#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define PAR(x) ((x) & 1)
#define MAX 5010
char s[MAX];

int sol()
{
	int dp[2][MAX], len, i, j;
	memset(dp, 0, sizeof(dp));
	len = strlen(s);
	for (i = 0; i < len; i++)
		for (j = 0; j < len; j++)
		{
			if (s[i] == s[len - j - 1]) dp[PAR(i + 1)][j + 1] = dp[PAR(i)][j] + 1;
			else dp[PAR(i + 1)][j + 1] = max(dp[PAR(i + 1)][j], dp[PAR(i)][j + 1]);
		}
	return dp[PAR(len)][len];
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%s", s);
		printf("%d\n", sol());
	}
}