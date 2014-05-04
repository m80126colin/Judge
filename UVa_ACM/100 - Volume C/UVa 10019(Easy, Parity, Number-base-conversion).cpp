#include <stdio.h>
#include <iostream>
using namespace std;

int s[10] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2};
int m, b1, b2;

int main()
{
	int t, tmp;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &m);
		for (b1 = 0, tmp = m; tmp; tmp >>= 1)
			if (tmp & 1) b1++;
		for (b2 = 0, tmp = m; tmp; tmp /= 10)
			b2 += s[tmp % 10];
		printf("%d %d\n", b1, b2);
	}
}