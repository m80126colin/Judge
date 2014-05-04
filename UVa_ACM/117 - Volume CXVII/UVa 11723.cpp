#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int r, n, c, cnt;
	for (cnt = 1; scanf("%d%d", &r, &n), (r || n); cnt++)
	{
		printf("Case %d: ", cnt);
		if (n >= r) puts("0");
		else
		{
			r -= n;
			c = r % n;
			r /= n;
			if (c) r++;
			if (r > 26) puts("impossible");
			else printf("%d\n", r);
		}
	}
}