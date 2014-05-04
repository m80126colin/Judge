#include <cstdio>
#include <iostream>
using namespace std;

int t, n, m;

int main()
{
	int c, ans;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d", &n, &m);
		c = ans = 0;
		while (n >= m)
		{
			c = n % m;
			ans += n / m;
			n = n / m + c;
		}
		if (n != 1) puts("cannot do this");
		else printf("%d\n", ans);
	}
}