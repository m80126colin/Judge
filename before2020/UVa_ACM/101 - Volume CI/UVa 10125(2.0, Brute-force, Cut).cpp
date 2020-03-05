#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int a[1005], n;
map<int, int> M;

bool sol(int x)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		if (i == x) continue;
		for (j = i + 1; j < n; j++)
		{
			if (j == x) continue;
			for (k = j + 1; k < n; k++)
			{
				if (k == x) continue;
				if (a[i] + a[j] + a[k] == a[x])
				{
					printf("%d\n", a[x]);
					return 0;
				}
			}
		}
	}
	return 1;
}

int main()
{
	int i;
	while (scanf("%d", &n), n)
	{
		M.clear();
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		for (i = n - 1; i && sol(i); i--);
		if (i <= 0) puts("no solution");
	}
}