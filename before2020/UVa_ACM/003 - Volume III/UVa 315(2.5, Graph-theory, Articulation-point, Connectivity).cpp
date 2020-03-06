/**
 *  @judge UVa
 *  @id 315
 *  @tag 2.5, Graph theory, Articulation Point, Connectivity
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 110
int n, timestamp;
int dfn[MAXN], low[MAXN];
int edge[MAXN][MAXN], istree[MAXN][MAXN];
int isroot[MAXN], child[MAXN];

int input()
{
	int i, j;
	scanf("%d", &n);
	if (n == 0) return 0;
	memset(edge, 0, sizeof(edge));
	while (scanf("%d", &i), i)
	{
		while (scanf("%d", &j) != EOF)
		{
			edge[i][j] = edge[j][i] = 1;
			if (cin.peek() == '\n') break;
		}
	}
	return n;
}

void DFS(int i, int p)
{
	dfn[i] = low[i] = ++timestamp;
	if (i == p) isroot[i] = 1;
	else istree[i][p] = istree[p][i] = 1;
	int j;
	for (j = 1; j <= n; j++)
	{
		if (edge[i][j])
		{
			if (dfn[j]) low[i] = min(low[i], dfn[j]);
			else
			{
				child[i]++;
				DFS(j, i);
				low[i] = min(low[i], low[j]);
			}
		}
	}
	return;
}

int is_articulation(int i)
{
	if (isroot[i])
		return child[i] > 1;
	int j;
	for (j = 1; j <= n; j++)
		if (edge[i][j] && istree[i][j] && low[j] >= dfn[i])
			return 1;
	return 0;
}

int articulation_point()
{
	int i, ans;
	ans = timestamp = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(isroot, 0, sizeof(isroot));
	memset(istree, 0, sizeof(istree));
	memset(child, 0, sizeof(child));
	for (i = 1; i <= n; i++)
		if (!dfn[i])
			DFS(i, i);
	for (i = 1; i <= n; i++)
		if (is_articulation(i))
			ans++;
	return ans;
}

int main()
{
	while (input())
		printf("%d\n", articulation_point());
}