#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int t, cnt, a, b, n;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &a, &b);
		a += ((a & 1) == 0);
		b -= ((b & 1) == 0);
		printf("Case %d: ", cnt);
		if (a > b) puts("0");
		else
		{
			n = (b - a) / 2 + 1;
			printf("%d\n", n * (n - 1 + a));
		}
	}
}