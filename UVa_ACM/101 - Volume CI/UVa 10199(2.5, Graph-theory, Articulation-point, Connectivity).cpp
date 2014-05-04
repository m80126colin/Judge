#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAXN 110
int n, m, timestamp;
map<string, int> city;
map<string, int>::iterator it;
int dfn[MAXN], low[MAXN];
int edge[MAXN][MAXN], istree[MAXN][MAXN];
int isroot[MAXN], child[MAXN], is_arti[MAXN];

int input()
{
	scanf("%d", &n);
	if (n == 0)
		return 0;
	int i, a, b, count = 0;
	string tmp, tmp2;
	city.clear();
	for (i = 0; i < n; i++)
	{
		cin >> tmp;
		city[tmp] = ++count;
	}
	scanf("%d", &m);
	memset(edge, 0, sizeof(edge));
	for (i = 0; i < m; i++)
	{
		cin >> tmp >> tmp2;
		a = city[tmp];
		b = city[tmp2];
		edge[a][b] = edge[b][a] = 1;
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
	return ;
}

int is_articulation(int i)
{
	if (isroot[i]) return child[i] > 1;
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
	memset(is_arti, 0, sizeof(is_arti));
	for (i = 1; i <= n; i++)
		if (!dfn[i]) DFS(i, i);
	for (i = 1; i <= n; i++)
		if (is_articulation(i))
		{
			is_arti[i] = 1;
			ans++;
		}
	return ans;
}

int main()
{
	int cnt;
	for (cnt = 1; input(); cnt++)
	{
		if (cnt > 1) puts("");
		printf("City map #%d: %d camera(s) found\n", cnt, articulation_point());
		for (it = city.begin(); it != city.end(); it++)
			if (is_arti[it->second]) puts((it->first).c_str());
	}
}