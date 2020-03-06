/**
 *  @judge ZeroJudge
 *  @id b231
 *  @tag Simple, Greedy
 */
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct sold
{
	int b, j;
	sold()
	{
		b = j = 0;
	}
	sold(int x, int y)
	{
		b = x, j = y;
	}
}Sold[1010];

int cmp(sold left, sold right)
{
	if (left.j != right.j) return left.j > right.j;
	return left.b < right.b;
}

int main()
{
	int t;
	int n, a, b, i, ans, res;
	for (t = 1; scanf("%d", &n) != EOF; t++)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			Sold[i] = sold(a, b);
		}
		sort(Sold, Sold + n, cmp);
		ans = res = 0;
		for (i = 0; i < n; i++)
		{
			ans = max(ans, res + Sold[i].b + Sold[i].j);
			res += Sold[i].b;
		}
		if (t > 1) puts("");
		printf("%d\n", ans);
	}
}