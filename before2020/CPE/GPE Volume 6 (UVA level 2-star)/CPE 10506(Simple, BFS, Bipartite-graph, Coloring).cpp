/**
 *  @judge CPE
 *  @id 10506
 *  @source UVa 10004
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 210
int n, m, node[MAX], edge[MAX][MAX];

inline int bfs()
{
	int i, x, y;
	vector<int> Q;
	Q.clear();
	Q.push_back(0);
	node[0] = 1;
	while (!Q.empty())
	{
		x = Q.front();
		Q.erase(Q.begin());
		for (i = 0; i < n; i++)
		{
			if (edge[x][i] == 0) continue;
			y = i;
			if (node[y] == node[x]) return 0;
			else if (!node[y])
			{
				if (node[x] == 1) node[y] = 2;
				else node[y] = 1;
				Q.push_back(y);
			}
		}
	}
	return 1;
}

int main()
{
	int a, b;
	while (scanf("%d", &n) != EOF)
	{
		scanf("%d", &m);
		memset(node, 0, sizeof(node));
		memset(edge, 0, sizeof(edge));
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			edge[a][b] = edge[b][a] = 1;
		}
		if (bfs()) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
}