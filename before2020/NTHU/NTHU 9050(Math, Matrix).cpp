#include <stdio.h>
#include <string.h>
#include <iostream>
#define M 110
using namespace std;

int main()
{
	int i, j, k;
	int t, m, n, p;
	int a[M][M], b[M][M], c[M][M];
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d", &m, &n, &p);
		for (i = 0; i < m; i++)
			for (k = 0; k < n; k++)
				scanf("%d", &a[i][k]);
		for (k = 0; k < n; k++)
			for (j = 0; j < p; j++)
				scanf("%d", &b[k][j]);
		for (i = 0; i < m; i++)
			for (j = 0; j < p; j++)
			{
				c[i][j] = 0;
				for (k = 0; k < n; k++)
					c[i][j] += a[i][k] * b[k][j];
			}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < p; j++)
			{
				if (j) putchar(' ');
				printf("%d", c[i][j]);
			}
			puts("");
		}
		puts("");
	}
}