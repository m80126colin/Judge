/**
 *  @judge CPE
 *  @id 11478
 *  @tag Easy, Ad hoc
 */
#include <stdio.h>
#include <iostream>
#define N 110
using namespace std;

long long mat[N][N];

int sym(int m)
{
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < m; j++)
			if (mat[i][j] < 0 || mat[i][j] != mat[m - 1 - i][m - 1 - j]) return 0;
	return 1;
}

int main()
{
	int n, ctr, i, j, M;
	char buf[10];
	for (scanf("%d", &n), ctr = 1; ctr <= n; ctr++)
	{
		scanf("%s%s%d", buf, buf, &M);
		for (i = 0; i < M; i++)
			for (j = 0; j < M; j++)
				scanf("%lld", &mat[i][j]);
		printf("Test #%d: ", ctr);
		if (sym(M)) puts("Symmetric.");
		else puts("Non-symmetric.");
	}
}