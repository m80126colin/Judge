/**
 *  @judge UVa
 *  @id 530
 *  @tag 1.5, Combination, Math
 */
#include <stdio.h>
#include <iostream>
using namespace std;

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

int n, m;

int main()
{
	while (scanf("%d%d", &n, &m), (n || m))
		printf("%lld\n", c(n, m));
}