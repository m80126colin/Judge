/**
 *  @judge UVa
 *  @id 10003
 *  @tag DP, Segment DP, Cutting stick
 */
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

#define N 60
#define INF 10000010
int L, n, log[N], dp[N][N];

int main() {
	while (scanf("%d", &L), L)
	{
		scanf("%d", &n);
		log[0] = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", &log[i]);
		log[n + 1] = L;
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (i == j) dp[i][j] = 0;
				else dp[i][j] = INF;
		for (int k = 1; k <= n; k++)
			for (int i = 0; i + k <= n; i++)
				for (int j = i; j < i + k; j++)
					dp[i][i + k] = min(dp[i][i + k], dp[i][j] + dp[j + 1][i + k] + log[i + k + 1] - log[i]);
		printf("The minimum cutting is %d.\n", dp[0][n]);
	}
}