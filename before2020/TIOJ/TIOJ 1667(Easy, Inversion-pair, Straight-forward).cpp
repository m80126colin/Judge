#include <stdio.h>
#include <iostream>
using namespace std;

int n, t, a[101];

int main()
{
	int i, j;
	while (scanf("%d", &n) != EOF)
	{
		for (i = t = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			for (j = 0; j < i; j++)
			{
				if (a[j] > a[i]) t++;
			}
		}
		printf("%d\n", t);
	}
}