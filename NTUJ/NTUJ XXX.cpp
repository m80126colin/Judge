#include <stdio.h>
#include <iostream>
#define mMAX 1000000007
#define M 1010
using namespace std;

long long dp[M][M];

int main()
{
	int i, j;
	for (i = 0; i < M; i++)
		dp[i][0] = 1;
	for (j = 0; j < M; j++)
		dp[j][j] = 0;
	for (i = 1; i < M; i++)
		for (j = 1; j < M; j++)
			dp[i][j] = ((dp[i - 1][j - 1] * (i - j)) % mMAX + (dp[i - 1][j] * (j + 1)) % mMAX) % mMAX;
	while (scanf("%d%d", &i, &j) != EOF) printf("%lld\n", dp[i][j]);
}