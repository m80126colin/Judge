#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define NMAX 110
#define SMAX 10010
int n, s, m[NMAX];
long long dp[SMAX];

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &s);
		for (int i = 0; i < n; i++)
			scanf("%d", &m[i]);
		sort(m, m + n);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = m[i]; j <= s; j++)
				dp[j] += dp[j - m[i]];
		printf("%lld\n", dp[s]);
	}
}