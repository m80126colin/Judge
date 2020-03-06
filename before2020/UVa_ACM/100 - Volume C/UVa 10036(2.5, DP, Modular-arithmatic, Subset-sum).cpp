/**
 *  @judge UVa
 *  @id 10036
 *  @tag 2.5, DP, Modular arithmatic, Subset sum
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 10010
#define KMAX 110
#define HASH(base, num, mod) ((((base) + (num)) % (mod) + (mod)) % (mod))
int m, n, k, a[MAX];
int dp[2][KMAX];

void input()
{
	int i;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i] = HASH(a[i], 0, k);
	}
	return ;
}

int check()
{
	int i, j;
	memset(dp, 0,sizeof(dp));
	dp[0][0] = 1;
	for (i = 0; i < n; i++)
	{
		memset(dp[(i + 1) & 1], 0, sizeof(dp[(i + 1) & 1]));
		for (j = 0; j < KMAX; j++)
		{
			if (dp[i & 1][j])
			{
				dp[(i + 1) & 1][HASH(j,  a[i], k)] = 1;
				dp[(i + 1) & 1][HASH(j, -a[i], k)] = 1;
			}
		}
	}
	return dp[i & 1][0];
}

int main()
{
	for (scanf("%d", &m); m; m--)
	{
		input();
		if (check()) puts("Divisible");
		else puts("Not divisible");
	}
}