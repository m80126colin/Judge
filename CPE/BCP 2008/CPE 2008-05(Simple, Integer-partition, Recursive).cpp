#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[40];

void dfs(int n, int p, int k)
{
	int i;
	if (!n)
	{
		for (i = 0; i < k; i++)
		{
			if (i) putchar(' ');
			printf("%d", a[i]);
		}
		puts("");
		return;
	}
	for (i = min(n, p); i; i--)
	{
		a[k] = i;
		dfs(n - i, i, k + 1);
	}
	return;
}

int main()
{
	int n, ctr;
	for (ctr = 1; cin >> n; ctr++)
	{
		printf("case %d:\n", ctr);
		dfs(n, n, 0);
		puts("");
	}
}