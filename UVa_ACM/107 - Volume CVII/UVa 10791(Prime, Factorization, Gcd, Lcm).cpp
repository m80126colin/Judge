#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int GCD(int a, int b)
{
	if (b) return GCD(b, a % b);
	return a;
}

int LCM(int a, int b)
{
	int g = GCD(a, b);
	return a / g * b;
}

int sol(int n)
{
	if (n == 1) return 0;
	int q, s, i;
	s = n + 1;
	q = sqrt((double) n) + 0.5;
	for (i = 2; i <= q; i++)
		if (n % i == 0 && n == LCM(i, n / i))
		{
			s = min(s, i + n / i);
			s = min(s, i + sol(n / i));
		}
	return s;
}

int main()
{
	int n, t;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		printf("Case %d: ", t);
		if (n == 2147483647) puts("2147483648");
		else if (n == 1) puts("2");
		else printf("%d\n", sol(n));
	}
}