#include <cstdio>
#include <iostream>
using namespace std;

int d[10], n;

void sol()
{
	int i, j, flag;
	for (i = 9; i > 1 && n > 1; i--)
		for (d[i] = 0; n % i == 0; d[i]++)
			n /= i;
	if (n > 1)
		puts("-1");
	else
	{
		flag = 1;
		for (i = 2; i < 10; i++)
			for (j = 0; j < d[i]; j++)
			{
				putchar('0' + i);
				flag = 0;
			}
		if (flag)
			putchar('1');
		puts("");
	}
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		sol();
	}
}