#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, a[24];

int sol()
{
	int i, j;
	for (i = 1; i < 24; i++)
	{
		for (j = 23; j > i; j--)
		{
			if (a[j] - a[i] == n)
			{
				printf("%d %d\n", j, i);
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	for (i = 1; i < 24; i++) a[i] = i * i * i;
	while (scanf("%d", &n), n)
	{
		if (!sol()) puts("No solution");
	}
}