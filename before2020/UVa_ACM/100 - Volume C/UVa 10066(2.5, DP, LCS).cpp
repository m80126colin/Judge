/**
 *  @judge UVa
 *  @id 10066
 *  @tag 2.5, DP, LCS
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
#define HASH(x) ((x) & 1)
int s1[MAX], s2[MAX];
int dp[2][MAX], len1, len2;

int input()
{
	int i;
	scanf("%d%d", &len1, &len2);
	for (i = 1; i <= len1; i++)
		scanf("%d", &s1[i]);
	for (i = 1; i <= len2; i++)
		scanf("%d", &s2[i]);
	return len1 + len2;
}

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
	int t;
	for (t = 1; input(); t++) printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", t, LCS());
}