/**
 *  @judge NTUJ
 *  @id 0359
 *  @tag 3.0, S t flow
 */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

#define N 110
#define MAX 0x7FFFFFFF
int n, s, t, c;
int path[N], flow[N];
int eg[N][N], net[N][N], re[N][N];

int input()
{
	int i, x, y, z;
	scanf("%d", &n);
	if (n == 0)
		return 0;
	memset(eg, 0, sizeof(eg));
	scanf("%d%d%d", &s, &t, &c);
	s--;
	t--;
	for (i = 0; i < c; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		eg[x - 1][y - 1] += z;
		eg[y - 1][x - 1] += z;
	}
	return n;
}

int bfs(int src, int dest)
{
	memset(flow, 0, sizeof(flow));
	memset(path, -1, sizeof(path));
	queue<int> Q;
	Q.push(src);
	path[src] = src;
	flow[src] = MAX;
	int i, j;
	while (!Q.empty())
	{
		i = Q.front();
		Q.pop();
		for (j = 0; j < n; j++)
		{
			if (path[j] == -1 && re[i][j] > 0)
			{
				path[j] = i;
				flow[j] = min(flow[i], re[i][j]);
				Q.push(j);
				if (j == dest)
					return flow[dest];
			}
		}
	}
	return 0;
}

int sol()
{
	int f, df, i, j;
	memset(net, 0, sizeof(net));
	memcpy(re, eg, sizeof(re));
	for (f = 0; df = bfs(s, t); f += df)
	{
		for (i = path[t], j = t; i != j; i = path[i], j = path[j])
		{
			net[i][j] += df;
			net[j][i] = -net[i][j];
			re[i][j] = eg[i][j] - net[i][j];
			re[j][i] = eg[j][i] - net[j][i];
		}
	}
	return f;
}

int main()
{
	int cnt;
	for (cnt = 1; input(); cnt++)
	{
		printf("Network %d\nThe bandwidth is %d.\n", cnt, sol());
	}
}