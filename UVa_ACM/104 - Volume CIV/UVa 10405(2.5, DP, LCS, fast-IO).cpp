#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 1010
#define HASH(x) ((x) & 1)
char s1[MAX], s2[MAX];
int dp[2][MAX], len1, len2;

int LCS()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	for (i = 1; i <= len1; i++)
		for (j = 1; j <= len2; j++)
			if (s1[i] == s2[j]) dp[HASH(i)][j] = dp[HASH(i - 1)][j - 1] + 1;
			else dp[HASH(i)][j] = max(dp[HASH(i - 1)][j], dp[HASH(i)][j - 1]);
	return dp[HASH(len1)][len2];
}

int main()
{
	while (gets(s1 + 1) && gets(s2 + 1))
	{
		len1 = strlen(s1 + 1);
		len2 = strlen(s2 + 1);
		printf("%d\n", LCS());
	}
}