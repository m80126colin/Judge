#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
char s1[MAX], s2[MAX];
int dp[MAX][MAX], len1, len2;

int LCS()
{
	int i, j;
	for (i = 0; i <= len1; i++) dp[i][0] = 0;
	for (j = 0; j <= len2; j++) dp[0][j] = 0;
	for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
			if (s1[i] == s2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[len1][len2];
}

int main()
{
	int t;
	for (t = 1; gets(s1 + 1), s1[1] != '#'; t++)
	{
		gets(s2 + 1);
		len1 = strlen(s1 + 1);
		len2 = strlen(s2 + 1);
		printf("Case #%d: you can visit at most %d cities.\n", t, LCS());
	}
}