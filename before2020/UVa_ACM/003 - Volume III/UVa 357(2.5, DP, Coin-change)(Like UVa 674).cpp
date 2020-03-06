/**
 *  @judge UVa
 *  @id 357
 *  @tag 2.5, DP, Coin change
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXC 5
#define MAXN 30010
int c[MAXC] = {1, 5, 10, 25, 50};
long long dp[MAXN];

int main()
{
	int i, j, n;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 0; i < MAXC; i++)
		for (j = c[i]; j < MAXN; j++)
			dp[j] += dp[j - c[i]];
	while (scanf("%d", &n) != EOF)
	{
		if (dp[n] > 1) printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
		else printf("There is only 1 way to produce %d cents change.\n", n);
	}
}