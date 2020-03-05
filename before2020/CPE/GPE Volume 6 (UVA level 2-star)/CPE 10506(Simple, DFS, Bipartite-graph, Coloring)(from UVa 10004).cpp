#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 210
int n, m, node[MAX], edge[MAX][MAX];

int dfs(int x)
{
	int i, ans = 1;
	for (i = 0; i < n; i++)
	{
		if (edge[x][i])
		{
			if (node[i] == node[x]) ans = 0;
			else if (!node[i])
			{
				if (node[x] == 1) node[i] = 2;
				else node[i] = 1;
				if (dfs(i) == 0) return 0;
			}
		}
	}
	return ans;
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
		node[0] = 1;
		if (dfs(0)) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
}