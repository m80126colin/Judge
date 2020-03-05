#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 1000010
struct edge
{
	int s, t;
}elist[3 * N];
int n, m;
vector<int> eg[N], w[N];
int low[N], dfn[N], cnt;
int res, ans[N];
struct frame
{
	int u, p, w;
	int i, v;
	frame() { u = p = w = i = v = 0; }
	frame(int u, int p, int w): u(u), p(p), w(w) { i = v = 0; }
}S[N];
int sn;

int input()
{
	int i, s, t;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
	{
		eg[i].clear();
		w[i].clear();
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d%d", &elist[i].s, &elist[i].t);
		s = elist[i].s;
		t = elist[i].t;
		eg[s].push_back(t);
		w[s].push_back(2 * i);
		eg[t].push_back(s);
		w[t].push_back(2 * i + 1);
	}
	return n + m;
}

void dfs(frame now)
{
	sn = 0;
start:
	low[now.u] = dfn[now.u] = ++cnt;
	for (now.i = 0; now.i < eg[now.u].size(); now.i++)
	{
		now.v = eg[now.u][now.i];
		if (!dfn[now.v])
		{
			S[sn++] = now;
			now = frame(now.v, now.u, w[now.u][now.i]);
			goto start;
		}
back:
		if (now.v != now.p) low[now.u] = min(low[now.u], low[now.v]);
	}
	if (now.u != now.p && low[now.u] > dfn[now.p])
		ans[res++] = now.w >> 1;
	if (sn)
	{
		now = S[--sn];
		goto back;
	}
	return ;
}

void sol()
{
	res = cnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	int i;
	for (i = 0; i < n; i++)
		if (!dfn[i])
			dfs(frame(i, i, -1));
	sort(ans, ans + res);
	for (i = 0; i < res; i++)
		printf("%d %d\n", elist[ans[i]].s, elist[ans[i]].t);
	if (res == 0)
		puts("None.");
}

int main()
{
	int t;
	for (t = 0; input(); t++)
	{
		if (t) puts("");
		sol();
	}
}