/**
 *  @judge UVa
 *  @id 11151
 *  @tag 2.5, DP, LCS, Palindrome
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1010
#define HASH(x) ((x) & 1)
char s[MAX];
int dp[2][MAX], len;

int LCS()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= len; i++)
		for (j = 1; j <= len; j++)
			if (s[i] == s[len - j + 1]) dp[HASH(i)][j] = dp[HASH(i - 1)][j - 1] + 1;
			else dp[HASH(i)][j] = max(dp[HASH(i - 1)][j], dp[HASH(i)][j - 1]);
	return dp[HASH(len)][len];
}

int main()
{
	int t;
	for (scanf("%d", &t), getchar(); t; t--)
	{
		gets(s + 1);
		len = strlen(s + 1);
		printf("%d\n", LCS());
	}
}