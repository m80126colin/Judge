/**
 *  @judge UVa
 *  @id 661
 *  @tag 1.5, Ad-hoc, Min max
 */
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define N 50
int n, m, c;
int a[N], st[N];

int main()
{
	int cnt, flag;
	for (cnt = 1; scanf("%d%d%d", &n, &m, &c), (n || m || c); cnt++)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			st[i] = 0;
		}
		int op, mx, cur;
		mx = cur = 0;
		flag = 0;
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &op);
			if (flag) continue;

			if (st[op - 1] == 1) cur -= a[op - 1];
			else cur += a[op - 1];
			st[op - 1] = !st[op - 1];

			if (cur > mx) mx = cur;
			if (mx > c) flag = 1;
		}
		printf("Sequence %d\n", cnt);
		if (flag) puts("Fuse was blown.");
		else
		{
			puts("Fuse was not blown.");
			printf("Maximal power consumption was %d amperes.\n", mx);
		}
		puts("");
	}
}