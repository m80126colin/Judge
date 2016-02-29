#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX 30
int n, m, c, a[MAX], b[MAX];

int main()
{
	int t, ans, tot, tmp;
	for (t = 1; scanf("%d %d %d", &n, &m, &c), (n || m || c); t++)
	{
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		tot = ans = 0;
		memset(b, 0, sizeof(b));
		for (int i = 0; i < m; i++)
		{
			scanf("%d", &tmp);
			tmp--;
			if (!b[tmp]) tot += a[tmp];
			else tot -= a[tmp];
			b[tmp] = !b[tmp];
			ans = max(tot, ans);
		}
		printf("Sequence %d\n", t);
		if (ans > c) puts("Fuse was blown.");
		else
		{
			puts("Fuse was not blown.");
			printf("Maximal power consumption was %d amperes.\n", ans);
		}
		puts("");
	}
}