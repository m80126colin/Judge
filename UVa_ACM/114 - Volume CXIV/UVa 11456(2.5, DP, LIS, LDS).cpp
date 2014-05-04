#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 2010
int n, t, a[MAX], lis[MAX], lds[MAX];

int main()
{
	int i, j, ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]), lis[i] = lds[i] = 1;
		for (j = n - 1; j >= 0; j--)
			for (i = n - 1; i > j; i--)
				if (a[j] > a[i])
					lds[j] = max(lds[j], lds[i] + 1);
		for (j = n - 1; j >= 0; j--)
			for (i = n - 1; i > j; i--)
				if (a[j] < a[i])
					lis[j] = max(lis[j], lis[i] + 1);
		ans = 0;
		for (i = 0; i < n; i++)
			ans = max(ans, lis[i] + lds[i] - 1);
		printf("%d\n", ans);
	}
}