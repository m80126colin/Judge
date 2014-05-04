#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define EPS 1e-7

int main()
{
	int t;
	long long ans, n, i, qn;
	for (t = 1; scanf("%lld", &n), n; t++)
	{
		ans = 0;
		qn = sqrt((double) n) + EPS;
		for (i = 2; i <= qn; i++)
		{
			ans += (n / i - 1) * i;
			ans += (n / i + qn + 1) * (n / i - qn) / 2;
		}
		printf("Case %d: %lld\n", t, ans);
	}
}