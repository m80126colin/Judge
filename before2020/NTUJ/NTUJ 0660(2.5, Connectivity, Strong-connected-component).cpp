#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

#define N 100010
int n, m;
vector<int> eg[N];
int con[N], low[N], dfn[N], cnt;
int instk[N], stk[N], sptr;

int input()
{
	int i, s, t;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		eg[i].clear();
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &s, &t);
		eg[s].push_back(t);
	}
	return n + m;
}

int dfs(int u)
{
	int i;
	low[u] = dfn[u] = ++cnt;
	stk[sptr++] = u;
	instk[u] = 1;
	for (i = 0; i < eg[u].size(); i++)
	{
		int v = eg[u][i];
		if (!dfn[v] || instk[v])
			low[u] = min(low[u], dfn[v]? low[v]: dfs(v));
	}
	if (dfn[u] == low[u])
	{
		do
		{
			--sptr;
			instk[stk[sptr]] = 0;
			con[stk[sptr]] = u;
		} while (sptr >= 0 && stk[sptr] != u);
	}
	return low[u];
}

int scc()
{
	int i;
	sptr = cnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(instk, 0, sizeof(instk));
	for (i = 0; i < n; i++)
		if (!dfn[i])
			dfs(i);
	int res = 0;
	for (i = 0; i < n; i++)
		if (con[i] == i)
			res++;
	return res;
}

int main()
{
	while (input())
		printf("%d\n", scc());
}