#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXC 5
#define MAXN 7490
int c[MAXC] = {1, 5, 10, 25, 50}, dp[MAXN];

int main()
{
	int i, j, n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 0; i < MAXC; i++)
		for (j = c[i]; j < MAXN; j++)
			dp[j] += dp[j - c[i]];
	while (scanf("%d", &n) != EOF)
		printf("%d\n", dp[n]);
}