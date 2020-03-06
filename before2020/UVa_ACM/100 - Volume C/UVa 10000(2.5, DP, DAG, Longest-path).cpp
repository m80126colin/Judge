/**
 *  @judge UVa
 *  @id 10000
 *  @tag 2.5, DP, DAG, Longest path
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define MAX 110
int M[MAX][MAX], s, n;
int timestamp, dfn[MAX], list[MAX];
int dp[MAX], ans, head;

void DFS(int node)
{
	int i;
	for (i = 1; i <= n; i++)
		if (M[node][i] && !dfn[i]) DFS(i);
	dfn[node] = ++timestamp;
	return ;
}

void TopoSort()
{
	timestamp = 0;
	memset(dfn, 0, sizeof(dfn));
	DFS(s);
	for (int i = 1; i <= n; i++)
		if (dfn[i])
		{
			list[timestamp - dfn[i] + 1] = i;
			dfn[i] = timestamp - dfn[i] + 1;
		}
	return ;
}

void LIS()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	ans = 0, head = 1;
	for (j = dfn[s]; j <= timestamp; j++)
		for (i = dfn[s]; i < j; i++)
			if (M[list[i]][list[j]])
			{
				if (dp[j] < dp[i] + 1) dp[j] = dp[i] + 1;
				if (ans < dp[j] || (ans == dp[j] && list[head] > list[j]))
				{
					ans = dp[j];
					head = j;
				}
			}
	return ;
}

int main()
{
	int a, b, t;
	for (t = 1; scanf("%d", &n), n; t++)
	{
		scanf("%d", &s);
		memset(M, 0, sizeof(M));
		while (scanf("%d%d", &a, &b), (a || b))
			M[a][b] = 1;
		TopoSort();
		LIS();
		printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", t, s, ans, list[head]);
	}
}