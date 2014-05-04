#include <stdio.h>
#include <iostream>
using namespace std;

int n, m, b;

int ItoX(int x)
{
	if (x / 10)
		return 16 * ItoX(x / 10) + (x % 10);
	return x;
}

int main()
{
	int tmp;
	for (scanf("%d", &n); n; n--)
	{
		scanf("%d", &m);
		for (b = 0, tmp = m; tmp; tmp /= 2)
			if (tmp & 1) b++;
		printf("%d ", b);
		m = ItoX(m);
		for (b = 0, tmp = m; tmp; tmp /= 2)
			if (tmp & 1) b++;
		printf("%d\n", b);
	}
}