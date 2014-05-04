#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100010
int n, m, cnt;
vector<int> edge[MAX], ans;
int dfn[MAX], idfn[MAX];

int dfs(int p, int x)
{
	int i, child = 0;
	bool ap = false;
	idfn[x] = dfn[x] = ++cnt;
	for (i = 0; i < edge[x].size(); i++)
	{
		int y = edge[x][i];
		if (y != p)
		{
			if (dfn[y]) idfn[x] = min(idfn[x], dfn[y]);
			else
			{
				child++;
				dfs(x, y);
				idfn[x] = min(idfn[x], idfn[y]);
				if (idfn[y] >= dfn[x]) ap = true;
			}
		}
	}
	if ((x == p && child > 1) || (x != p && ap))
		ans.push_back(x);
	return idfn[x];
}

int main()
{
	int i, flag;
	for (flag = 0; scanf("%d%d", &n, &m), (n || m); flag++)
	{
		for (i = 0; i < n; i++) edge[i].clear();
		for (i = 0; i < m; i++)
		{
			int s, t;
			scanf("%d%d", &s, &t);
			edge[s].push_back(t);
			edge[t].push_back(s);
		}
		memset(dfn, 0, sizeof(dfn));
		memset(idfn, 0, sizeof(idfn));
		cnt = 0;
		ans.clear();
		for (i = 0; i < n; i++)
			if (!dfn[i]) dfs(i, i);
		if (flag) puts("");
		if (ans.size())
		{
			sort(ans.begin(), ans.end());
			for (i = 0; i < ans.size(); i++)
				printf("%d\n", ans[i]);
		}
		else puts("None.");
	}
}