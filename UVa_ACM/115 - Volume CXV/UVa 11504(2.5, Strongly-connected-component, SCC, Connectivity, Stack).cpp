#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 100010
int n, m, timestamp;
int dfn[MAXN], low[MAXN], new_node[MAXN];
int stack[MAXN], in_stack[MAXN], sptr;
vector<int> edge[MAXN];

void input()
{
	int i, a, b;
	scanf("%d%d", &n, &m);
	for (i = 0; i <= n; i++)
		edge[i].clear();
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
	}
	return ;
}

int sys_stack[MAXN], sys_vary[MAXN], sys_ptr;

void DFS(int u)
{
	int i, v;
First:
	sys_stack[sys_ptr++] = u;
	dfn[u] = low[u] = ++timestamp;
	stack[sptr++] = u;
	in_stack[u] = 1;
	for (i = 0; i < edge[u].size(); i++)
	{
		v = edge[u][i];
		if (!dfn[v])
		{
			sys_vary[sys_ptr - 1] = i;
			u = v;
			goto First;
		}
Second:
		if (in_stack[v])
			low[u] = min(low[u], low[v]);
	}
	if (dfn[u] == low[u])
	{
		do
		{
			i = stack[--sptr];
			in_stack[i] = 0;
			new_node[i] = u;
		} while (sptr && i != u);
	}
	v = u;
	--sys_ptr;
	if (sys_ptr <= 0) return ;
	u = sys_stack[sys_ptr - 1];
	i = sys_vary[sys_ptr - 1];
	goto Second;
	return ;
}

void SCC()
{
	int i, ans;
	ans = timestamp = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(new_node, 0, sizeof(new_node));
	memset(in_stack, 0, sizeof(in_stack));
	sptr = sys_ptr = 0;
	for (i = 1; i <= n; i++)
		if (!dfn[i]) DFS(i);
	return ;
}

int indeg[MAXN];

int sol()
{
	int i, u, v, ans = 0;
	memset(indeg, 0, sizeof(indeg));
	for (u = 1; u <= n; u++)
	{
		for (i = 0; i < edge[u].size(); i++)
		{
			v = edge[u][i];
			if (new_node[u] != new_node[v])
				indeg[new_node[v]]++;
		}
	}
	for (u = 1; u <= n; u++)
		if (u == new_node[u] && !indeg[u]) ans++;
	return ans;
}

int main()
{
	int t;
	for (scanf("%d", &t); t; t--)
	{
		input();
		SCC();
		printf("%d\n", sol());
	}
}