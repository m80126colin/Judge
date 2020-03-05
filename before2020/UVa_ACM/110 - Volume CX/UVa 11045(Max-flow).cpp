#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <map>
#define M 40
using namespace std;

map <string, int> s;
bool visited[M];
int flow[M], path[M];
int edge[M][M], remain[M][M];
int n, m;

int BFS(int s, int t)
{
	int i, j;
	memset(visited, 0, sizeof(visited));
	memset(flow, 0, sizeof(flow));
	memset(path, 0, sizeof(path));
	queue <int> Q;
	flow[s] = 2100000000;
	Q.push(s);
	visited[s] = true;
	while (!Q.empty())
	{
		i = Q.front();
		Q.pop();
		for (j = 1; j <= 7+m; j++)
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
		i = path[t];
		for (j = t; j != i; i = path[j = i])
		{
			remain[i][j] -= df;
			remain[j][i] += df;
		}
	}
	return f;
}

int main()
{
	int t, i, j, ca, cb;
	string a, b;
	s.clear();
	s["XXL"] = 1;
	s["XL"] = 2;
	s["L"] = 3;
	s["M"] = 4;
	s["S"] = 5;
	s["XS"] = 6;
	for (scanf("%d",&t); t;-t--)
	{
		scanf("%d%d", &n, &m);
		memset(edge, 0, sizeof(edge));
		/* 1 ~ 6 T-shirt size, 6+i ~ 6+m people in, 0 source, 6+m+1 sink */
		for (i = 1; i <= m; i++)
		{
			cin >> a >> b;
			ca = s[a], cb = s[b];
			edge[ca][6 + i] = 1;
			edge[cb][6 + i] = 1;
			edge[6 + i][6 + m + 1] = 1;
		}
		for (j = n/6, i = 1; i <= 6; i++)
		{
			edge[0][i] = j;
		}
		if (EK_flow(0, 7+m) == m) puts("YES");
		else puts("NO");
	}
}