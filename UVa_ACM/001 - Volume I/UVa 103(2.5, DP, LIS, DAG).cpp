#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 15
#define MAXK 40
int k, n;
struct box
{
	int a[MAXN], w;
	bool operator < (const box& b) const
	{
		int i;
		for (i = 0; i < n; i++)
			if (a[i] != b.a[i])
				return a[i] < b.a[i];
		return 0;
	}
}b[MAXK];
int dp[MAXK], path[MAXK], ans, head;

int inner(const box& A, const box& B)
{
	for (int i = 0; i < n; i++)
		if (A.a[i] >= B.a[i]) return 0;
	return 1;
}

int main()
{
	int i, j;
	while (scanf("%d%d", &k, &n) != EOF)
	{
		for (i = 0; i < k; i++)
		{
			for (j = 0; j < n; j++)
				scanf("%d", &b[i].a[j]);
			b[i].w = i + 1;
			sort(b[i].a, b[i].a + n);
		}
		sort(b, b + k);
		ans = (k != 0);
		head = 0;
		for (i = 0; i < k; i++)
		{
			dp[i] = 1;
			path[i] = k;
		}
		for (j = k - 1; j >= 0; j--)
			for (i = k - 1; i > j; i--)
				if (inner(b[j], b[i]) && dp[j] < dp[i] + 1)
				{
					dp[j] = dp[i] + 1;
					path[j] = i;
					if (ans < dp[j])
					{
						ans = dp[j];
						head = j;
					}
				}
		printf("%d\n", ans);
		for (i = 0; i < ans; i++)
		{
			printf("%d", b[head].w);
			head = path[head];
			if (ans > 1) putchar(' ');
		}
		if (ans) puts("");
	}
}