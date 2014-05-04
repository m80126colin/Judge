#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 25
#define NMAX 2010
int a[MAX], ans[NMAX], n, t;
bool dp[NMAX];

int main()
{
	int i, j;
	while (scanf("%d%d", &n, &t) != EOF)
	{
		for (i = 0; i < t; i++)
			scanf("%d", &a[i]);
		memset(ans, 0, sizeof(ans));
		memset(dp, 0, sizeof(dp));
		dp[0] = true;
		for (i = 0; i < t; i++)
		{
			for (j = n - 1; j >= 0; j--)
			{
				if (dp[j] && j + a[i] <= n)
				{
					dp[j + a[i]] |= dp[j];
					ans[j + a[i]] = (ans[j] | (1 << i));
				}
			}
		}
		for (j = n; j >= 0; j--)
			if (dp[j]) break;
		for (i = 0; i < t; i++)
		{
			if (ans[j] & (1 << i))
				printf("%d ", a[i]);
		}
		printf("sum:%d\n", j);
	}
}