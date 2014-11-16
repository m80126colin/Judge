#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 40
#define NMAX 1010
int t, w, n, cnt, d[MAX], v[MAX], c[MAX];
int dp[NMAX], num[NMAX], ans[NMAX], mx, pos;

int input()
{
	int i;
	if (scanf("%d%d", &t, &w) == EOF)
		return EOF;
	if (scanf("%d", &n) == EOF)
		return EOF;
	for (i = 0; i < n; i++)
	{
		if (scanf("%d%d", &d[i], &v[i]) == EOF)
			return EOF;
		c[i] = 3 * w * d[i];
	}
	return 0;
}

void DP()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	memset(num, 0, sizeof(num));
	memset(ans, 0, sizeof(ans));
	mx = pos = 0;
	dp[0] = 1;
	for (i = 0; i < n; i++)
	{
		for (j = t - c[i]; j >= 0; j--)
		{
			if (dp[j] && j + c[i] <= t && num[j + c[i]] < num[j] + v[i])
			{
				dp[j + c[i]] = dp[j] + 1;
				num[j + c[i]] = num[j] + v[i];
				ans[j + c[i]] = (ans[j] | (1 << i));
				if (mx < num[j + c[i]])
				{
					mx = num[j + c[i]];
					pos = j + c[i];
				}
			}
		}
	}
	return ;
}

void print()
{
	if (cnt) puts("");
	printf("%d\n%d\n", mx, dp[pos] - 1);
	int i;
	for (i = 0; i < n; i++)
		if (ans[pos] & (1 << i))
			printf("%d %d\n", d[i], v[i]);
	return ;
}

int main()
{
	for (cnt = 0; input() != EOF; cnt++)
	{
		DP();
		print();
	}
}