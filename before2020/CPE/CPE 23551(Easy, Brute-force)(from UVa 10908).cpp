/**
 *  @judge CPE
 *  @id 23551
 *  @tag Easy, Brute force
 */
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 110
int m, n, q;
char mat[MAX][MAX];

int legth(int i, int j)
{
	int L, k;
	for (L = 1; ; L += 2)
	{
		if (i - L / 2 < 0 || i + L / 2 >= m || j - L / 2 < 0 || j + L / 2 >= n)
		{
			L -= 2;
			break;
		}
		int a, b, c, d;
		a = i - L / 2;
		b = j - L / 2;
		c = i + L / 2;
		d = j + L / 2;
		for (k = 0; k < L; k++)
		{
			if ( !(mat[i][j] == mat[a + k][b] && mat[i][j] == mat[a][d - k] && mat[i][j] == mat[c][b + k] && mat[i][j] == mat[c - k][d]) )
			{
				L -= 2;
				return L;
			}
		}
	}
	return L;
}

int main()
{
	int t, i, j, k;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d", &m, &n, &q);
		cin.ignore(1);

		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
				mat[i][j] = getchar();
			getchar();
		}
		printf("%d %d %d\n", m, n, q);

		for (k = 0; k < q; k++)
		{
			//puts("reach");
			scanf("%d%d", &i, &j);
			printf("%d\n", legth(i, j));
		}
	}
}