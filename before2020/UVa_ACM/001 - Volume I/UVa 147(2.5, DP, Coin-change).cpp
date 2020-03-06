/**
 *  @judge UVa
 *  @id 147
 *  @tag 2.5, DP, Coin change
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MOD 5
#define MAXC 11
#define MAXN 30010
int c[MAXC] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
long long dp[MAXN];

int main()
{
	int i, j, t1, t2;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 0; i < MAXC; i++)
		for (j = c[i] / MOD; j < MAXN / MOD; j++)
			dp[j] += dp[j - c[i] / MOD];
	while (scanf("%d.%d", &t1, &t2), (t1 || t2))
		printf("%3d.%02d%17lld\n", t1, t2, dp[(t1 * 100 + t2) / MOD]);
}