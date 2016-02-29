#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 100010
#define NMAX 100010
int a[MAX], dp[MAX], n;

int input()
{
	for (n = 0; scanf("%d", &a[n + 1]), a[n + 1] != -1; n++) ;
	a[0] = NMAX;
	return n;
}

int LIS()
{
	int i, j, mx;
	memset(dp, 0, sizeof(dp));
	mx = dp[0] = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < i; j++)
			if (a[i] <= a[j]) dp[i] = max(dp[i], dp[j] + 1);
		mx = max(mx, dp[i]);
	}
	return mx;
}

int main()
{
	int cnt;
	for (cnt = 1; input(); cnt++)
	{
		if (cnt > 1) puts("");
		printf("Test #%d:\n  maximum possible interceptions: %d\n", cnt, LIS());
	}
}