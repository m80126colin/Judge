/**
 *  @judge UVa
 *  @id 11709
 *  @tag 2.5, Strongly connected component, SCC, Connnectivity
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define MAXN 1010
#define SLEN 110
int n, m, timestamp;
int dfn[MAXN], low[MAXN], newnode[MAXN];
int instack[MAXN], stack[MAXN], sptr;
map<string, int> hash;
vector<int> edge[MAXN];

int input()
{
	scanf("%d%d", &n, &m);
	if (!(n + m))
		return 0;
	getchar();
	int i;
	char str[SLEN], str2[SLEN];
	hash.clear();
	for (i = 1; i <= n; i++)
	{
		gets(str);
		hash[str] = i;
		edge[i].clear();
	}
	for (i = 0; i < m; i++)
	{
		gets(str);
		gets(str2);
		edge[hash[str]].push_back(hash[str2]);
	}
	return n + m;
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
	int u;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(newnode, 0, sizeof(newnode));
	memset(instack, 0, sizeof(instack));
	sptr = timestamp = 0;
	for (u = 1; u <= n; u++)
		if (!dfn[u]) DFS(u);
	return ;
}

int sol()
{
	int i, ans = 0;
	for (i = 1; i <= n; i++)
		if (newnode[i] == i) ans++;
	return ans;
}

int main()
{
	while (input())
	{
		SCC();
		printf("%d\n", sol());
	}
}