/**
 *  @judge NTUJ
 *  @id 0349
 *  @source UVa 534
 * 
 *  @tag 2.5, DP, Shortest path, Minimum Spanning Tree
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

#define N 210
struct point
{
	int x, y;
}p[N];
int n, dp[N][N];

int input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i].x, &p[i].y);
	return n;
}

void sol()
{
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 1; j < n; j++)
			dp[i][j] = dp[j][i] = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				dp[i][j] = min(dp[i][j], max(dp[i][k], dp[k][j]));
	printf("%.3lf\n", sqrt((double)dp[0][1]));
}

int main()
{
	int t;
	for (t = 1; input(); t++)
	{
		printf("Scenario #%d\nFrog Distance = ", t);
		sol();
		puts("");
	}
}