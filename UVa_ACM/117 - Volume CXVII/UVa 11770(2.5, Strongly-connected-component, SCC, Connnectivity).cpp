#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 10010
int n, m, timestamp;
int dfn[MAXN], low[MAXN], newnode[MAXN];
int instack[MAXN], stack[MAXN], sptr;
vector<int> edge[MAXN];

void input()
{
	scanf("%d%d", &n, &m);
	int i, a, b;
	for (i = 0; i <= n; i++)
		edge[i].clear();
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
	}
	return ;
}

void DFS(int u)
{
	int i, v;
	dfn[u] = low[u] = ++timestamp;
	stack[sptr++] = u;
	instack[u] = 1;
	for (i = 0; i < edge[u].size(); i++)
	{
		v = edge[u][i];
		if (!dfn[v]) DFS(v);
		if (instack[v]) low[u] = min(low[u], low[v]);
	}
	if (dfn[u] == low[u])
	{
		do
		{
			i = stack[--sptr];
			instack[i] = 0;
			newnode[i] = u;
		} while (sptr && i != u);
	}
	return ;
}

void SCC()
{
	int i;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(newnode, 0, sizeof(newnode));
	memset(instack, 0, sizeof(instack));
	sptr = timestamp = 0;
	for (i = 1; i <= n; i++)
		if (!dfn[i]) DFS(i);
}

int indeg[MAXN];

int sol()
{
	memset(indeg, 0, sizeof(indeg));
	int i, u, v, ans = 0;
	for (u = 1; u <= n; u++)
		for (i = 0; i < edge[u].size(); i++)
		{
			v = edge[u][i];
			if (newnode[u] != newnode[v])
				indeg[newnode[v]]++;
		}
	for (u = 1; u <= n; u++)
		if (newnode[u] == u && !indeg[u])
			ans++;
	return ans;
}

int main()
{
	int t, cnt;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		input();
		SCC();
		printf("Case %d: %d\n", cnt, sol());
	}
}