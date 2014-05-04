#include <stdio.h>
#include <iostream>
using namespace std;

int n, m;

long long c(int a, int b)
{
	long long ans, i, j, mn, mx;
	ans = 1;
	mn = min(a - b, b);
	mx = max(a - b, b);
	for (i = a, j = 1; i > mx; i--)
	{
		ans *= i;
		if (j <= mn)
		{
			ans /= j;
			j++;
		}
	}
	for (; j <= mn; j++)
		ans /= j;
	return ans;
}

int main()
{
	while (scanf("%d%d", &n, &m), (n || m))
		printf("%d things taken %d at a time is %lld exactly.\n", n, m, c(n, m));
}