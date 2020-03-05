#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXC 22
#define MAXN 10010
int c[MAXC];
long long dp[MAXN];

int main()
{
	int i, j, n;
	for (i = 1; i < MAXC; i++)
		c[i] = i * i * i;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 1; i < MAXC; i++)
		for (j = c[i]; j < MAXN; j++)
			dp[j] += dp[j - c[i]];
	while (scanf("%d", &n) != EOF)
		printf("%lld\n", dp[n]);
}