/**
 *  @judge UVa
 *  @id 10664
 *  @tag 2.5, 01-Knapsack, Subset Sum
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAXN 25
#define MAX 110
int n, m, sum, a[MAXN], dp[MAX];

void input()
{
	char ch = '0';
	for (sum = m = 0; ch != '\n'; m++)
	{
		scanf("%d%c", &a[m], &ch);
		sum += a[m];
	}
	return ;
}

int knapsack()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	sum >>= 1;
	for (j = 0; j < m; j++)
		for (i = sum - 1; i >= 0; i--)
			if (dp[i] && i + a[j] <= sum)
				dp[i + a[j]] = 1;
	return dp[sum];
}

int main()
{
	for (scanf("%d", &n); n; n--)
	{
		input();
		if (sum & 1 || !knapsack()) puts("NO");
		else puts("YES");
	}
}