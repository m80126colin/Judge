/**
 *  @judge ZeroJudge
 *  @id d667
 *  @tag Max Flow
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#define MAX 110
using namespace std;

bool visited[MAX];
int path[MAX], flow[MAX];
int E[MAX][MAX], Eflow[MAX][MAX], Emain[MAX][MAX];
int n, m;

int BFS(int s, int t)
{
	int i, j;
	memset(visited, 0, sizeof (visited));
	memset(path, 0, sizeof(path));
	memset(flow, 0, sizeof(flow));
	queue <int> Q;
	visited[s] = true;
	path[s] = s;
	flow[s] = 0X7FFFFFFF;
	Q.push(s);
	while (!Q.empty())
	{
		i = Q.front();
		Q.pop();
		for (j = 1; j <= n; j++)
		{
			if (!visited[j] && Emain[i][j] > 0)
			{
				visited[j] = true;
				path[j] = i;
				flow[j] = min(flow[i], Emain[i][j]);
				Q.push(j);
				if (j == t) return flow[t];
			}
		}
	}
	return flow[t];
}

int EK_flow(int s, int t)
{
	memset(Eflow, 0, sizeof(Eflow));
	memcpy(Emain, E, sizeof(E));

	int f, df, i, j;
	for (f = 0; df = BFS(s, t); f += df)
	{
		for (i = path[t], j = t; i != j; i = path[j = i])
		{
			Eflow[i][j] += df;
			Eflow[j][i] = -Eflow[i][j];
			Emain[i][j] = E[i][j] - Eflow[i][j];
			Emain[j][i] = E[j][i] - Eflow[j][i];
		}
	}
	return f;
}

int main()
{
	int ctr;
	int i, s, t;
	int a, b, c;
	for (ctr = 1; scanf("%d", &n) , n; ctr++)
	{
		scanf("%d%d%d", &s, &t, &m);
		memset(E, 0, sizeof(E));
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			E[a][b] += c, E[b][a] += c;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", ctr, EK_flow(s, t));
	}
}