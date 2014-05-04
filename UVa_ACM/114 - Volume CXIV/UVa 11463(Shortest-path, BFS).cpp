#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#define N 110
using namespace std;

int n, r, edge[N][N];

int main()
{
	int t, cnt, a, b;
	int i, j, k;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d", &n, &r);
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				edge[i][j] = ((i == j) ? 0: 10000);
		for (i = 0; i < r; i++)
		{
			scanf("%d%d", &a, &b);
			edge[a][b] = edge[b][a] = 1;
		}
		scanf("%d%d", &a, &b);
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
		int ans = 0;
		for (k = 0; k < n; k++)
			ans = max(ans, edge[a][k] + edge[k][b]);
		printf("Case %d: %d\n", cnt, ans);
	}
}