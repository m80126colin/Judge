#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 110
#define NMAX 50010
int m, a[MAX], sum;
bool dp[NMAX];

int main()
{
	int t, i, j;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &m);
		for (i = sum = 0; i < m; i++)
		{
			scanf("%d", &a[i]);
			sum += a[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = true;
		for (j = 0; j < m; j++)
			for (i = NMAX - 1; i >= 0; i--)
				if (dp[i] && i + a[j] < NMAX) dp[i + a[j]] |= dp[i];
		for (i = sum / 2; i >= 0; i--)
			if (dp[i]) break;
		printf("%d\n", sum - 2 * i);
	}
}