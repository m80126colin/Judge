#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 120
struct brick
{
	long long a[3];
}b[MAX];
int n;
long long dp[MAX];

int cmp(brick left, brick right)
{
	if (left.a[0] != right.a[0]) 
		return left.a[0] > right.a[0];
	return left.a[1] > right.a[1];
}

int input()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
			scanf("%lld", &b[3 * i].a[j]);
		sort(b[3 * i].a, b[3 * i].a + 3);
		b[3 * i + 1].a[0] = b[3 * i].a[0];
		b[3 * i + 1].a[1] = b[3 * i].a[2];
		b[3 * i + 1].a[2] = b[3 * i].a[1];
		b[3 * i + 2].a[0] = b[3 * i].a[1];
		b[3 * i + 2].a[1] = b[3 * i].a[2];
		b[3 * i + 2].a[2] = b[3 * i].a[0];
	}
	sort(b, b + 3 * n, cmp);
	return n;
}

void init()
{
	int i;
	for (i = 0; i < 3 * n; i++) dp[i] = b[i].a[2];
	return ;
}

long long LIS()
{
	int i, j;
	long long mx = 0;
	for (i = 0; i < 3 * n; i++)
		for (j = 0; j < i; j++)
			if (b[i].a[0] < b[j].a[0] && b[i].a[1] < b[j].a[1])
			{
				dp[i] = max(dp[i], dp[j] + b[i].a[2]);
				mx = max(mx, dp[i]);
			}
	return mx;
}

int main()
{
	int cnt;
	for (cnt = 1; input(); cnt++)
	{
		init();
		printf("Case %d: maximum height = %lld\n", cnt, LIS());
	}
}