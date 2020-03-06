/**
 *  @judge CPE
 *  @id 11481
 *  @tag Easy, Ad hoc
 */
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, a[11][11], i, j, ctr, sum;
	for (ctr = 1; scanf("%d", &n), n; ctr++)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		printf("Case %d:", ctr);
		for (i = 0; i < n / 2; i ++)
		{
			sum = 0;
			for (j = 0; j < n - 2 * i - 1; j++)
				sum += a[i][i + j] + a[i + j][n - 1 - i] + a[n - 1 - i][(n - 1 - i) - j] + a[(n - 1 - i) - j][i];
			printf(" %d", sum);
		}
		if (n & 1) printf(" %d", a[n / 2][n / 2]);
		puts("");
	}
}