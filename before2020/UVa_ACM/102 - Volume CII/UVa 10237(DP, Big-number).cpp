#include <stdio.h>
#include <string.h>
#include <iostream>
#define N 55
using namespace std;

double len[N], DP[N][N * N], ans[N][N * N];

int main()
{
	int i, j, k, tp, tp2;
	len[0] = 0, len[1] = 2;
	for (i = 2; i <= 50; i++) len[i] = len[i - 2] + 2;
	memset(DP, 0, sizeof(DP));
	for (i = 0; i <= 50; i++) DP[i][0] = 1;
	for (i = 1; i <= 50; i++)
		for (j = 1; j <= len[i]; j++)
			DP[i][j] = (len[i] - j + 1) * DP[i - 1][j - 1] + DP[i - 1][j];
	for (i = 1; i <= 50; i++)
	{
		tp = tp2 = i - 1;
		if (i & 1) tp++;
		for (j = 1; j <= i * i; j++)
			for (k = 0; k <= j; k++)
			{
				if (k <= len[tp] && j - k <= len[tp2])
					ans[i][j] += DP[tp][k] * DP[tp2][j - k];
			}
	}
	while (scanf("%d%d", &i, &j) != EOF)
		printf("%.lf\n", ans[i][j]);
}