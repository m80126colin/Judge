/**
 *  @judge UVa
 *  @id 12455
 *  @tag DP, 01 Knapsack
 */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define N 1010
#define L 20010
int t, n, p, dp[L], a[N];

int main()
{
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &p);
		for (int i = 0; i < p; i++)
			scanf("%d", &a[i]);
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int j = 0; j < p; j++)
			for (int i = n; i >= a[j]; i--)
				if (dp[i - a[j]]) dp[i] = dp[i - a[j]];
		if (dp[n]) puts("YES");
		else puts("NO");
	}
}