#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
long long ans[9];

int sec(long long p[], int len, int k)
{
	if (k >= n) return !len;
	int i, j, s;
	long long b[36], tmp;
	ans[k] = p[0] - ans[0];
	for (i = 0; i < k; i++) if (ans[i] > ans[k]) return 0;
	s = 0;
	for (i = j = 1; i < k; i++)
	{
		if (j >= len) break;
		tmp = ans[i] + ans[k];
		while (j < len && p[j] != tmp) b[s++] = p[j++];
		j++;
	}
	if (j < len)
	{
		while (j < len) b[s++] = p[j++];
	}
	return sec(b, s, k+1);
}

int first(long long p[])
{
	int i, j, k;
	long long b[36], tmp;
	for (i = 2; i < m; i++)
	{
		tmp = (p[0] + p[1] - p[i]) / 2;
		if (2 * (tmp + p[i]) == p[0] + p[1] + p[i])
		{
			k = 0;
			for (j = 2; j < m; j++)
			{
				if (i != j) b[k++] = p[j];
			}
			ans[0] = tmp;
			ans[1] = p[0] - tmp;
			ans[2] = p[1] - tmp;
			if (sec(b, k, 3)) return 1;
		}
	}
	return 0;
}

int main()
{
	int i;
	long long a[36];
	while (scanf("%d", &n) != EOF)
	{
		m = n * (n - 1) / 2;
		for (i = 0; i < m; i++) scanf("%lld", &a[i]);
		sort(a, a+m);
		if (!first(a)) puts("Impossible");
		else {
			for (i = 0; i < n; i++) {
				if (i) putchar(' ');
				printf("%d", ans[i]);
			}
			puts("");
		}
	}
}