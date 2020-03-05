#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;

#define MAXN 10010
#define INF 2100000000
int n, co, dp[MAXN], M[MAXN];

void input()
{
	int i;
	scanf("%d%d", &co, &n);
	for (i = 0; i < n; i++)
		scanf("%d", &M[i]);
	return ;
}

void knapsack()
{
	int i, j;
	for (i = 1; i < MAXN; i++)
		dp[i] = INF;
	dp[0] = 0;
	for (i = 0; i < n; i++)
		for (j = MAXN - 1; j >= 0; j--)
			if (dp[j] < INF && j + M[i] < MAXN)
				dp[j + M[i]] = min(dp[j + M[i]], dp[j] + 1);
	return ;
}

void sol()
{
	int i;
	for (i = co; i < MAXN; i++)
		if (dp[i] < INF)
		{
			printf("%d %d\n", i, dp[i]);
			return ;
		}
	return ;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		input();
		knapsack();
		sol();
	}
}