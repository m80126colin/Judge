#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, k, a[150];
	int i;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		for (i = 0; i < n; i++)
			scanf("%d", &a[i]);
		int ans = 0;
		for (i = 0; i < n; i++)
			ans += (a[i] >= a[k - 1] && a[i] > 0);
		printf("%d\n", ans);
	}
}