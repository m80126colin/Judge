#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int mx, mn, n, i, a[110];
	while (scanf("%D", &n) != EOF)
	{
		mn = mx = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[mn] >= a[i]) mn = i;
			if (a[mx] < a[i]) mx = i;
		}
		if (mn > mx) printf("%d\n", (n - 1 - mn) + mx);
		else if (mn < mx) printf("%d\n", (n - 1 - mn) + (mx - 1));
		else puts("0");
	}
}