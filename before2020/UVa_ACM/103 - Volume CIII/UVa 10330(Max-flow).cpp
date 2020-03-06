/**
 *  @judge UVa
 *  @id 10330
 *  @tag Max flow
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <queue>
#include <vector>
#define M 210
#define INTMX 2100000000
using namespace std;

bool visited[M];
int flow[M], path[M];
int edge[M][M], remain[M][M];
int n, m, d, b;

int BFS(int s, int t)
{
	memset(visited, 0 , sizeof(visited));
	memset(path, 0, sizeof(path));
	memset(flow, 0, sizeof(flow));
	flow[s] = INTMX;
	visited[s] = true;
	queue <int> Q;
	Q.push(s);
	int i, j;
	while (!Q.empty())
	{
		i = Q.front();
		Q.pop();
		for (j = 1; j <= 2*n+1; j++)
		{
			if (!visited[j] && remain[i][j] > 0)
			{
				visited[j] = true;
				flow[j] = min(flow[i], remain[i][j]);
				path[j] = i;
				Q.push(j);
				if (j == t) return flow[t];
			}
		}
	}
	return flow[t];
}

int EK_flow(int s, int t)
{
	memcpy(remain, edge, sizeof(edge));
	int f, df, i, j;
	for (f = 0; df = BFS(s, t); f += df)
	{
		for (i = path[t], j = t; i != j; i = path[j = i])
		{
			remain[i][j] -= df;
			remain[j][i] += df;
		}
	}
	return f;
}

int main()
{
	int i, a, b, c;
	while (scanf("%d", &n) != EOF)
	{
		memset(edge, 0, sizeof(edge));
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &c);
			edge[i][i+n] += c;
		}
		scanf("%d", &m);
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			edge[a+n][b] += c;
		}
		scanf("%d%d", &b, &d);
		for (i = 1; i <= b; i++)
		{
			scanf("%d", &a);
			edge[0][a] = INTMX;
		}
		for (i = 1; i <= d; i++)
		{
			scanf("%d", &a);
			edge[a+n][2*n+1] = INTMX;
		}
		printf("%d\n", EK_flow(0, 2*n+1));
	}
}