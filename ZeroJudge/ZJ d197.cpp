#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100010
using namespace std;

/*SCC*/
vector <int> edge[MAX];
bool instack[MAX];
int dfn[MAX], low[MAX], dfsid, stk[MAX], sptr;
int contract[MAX];
int n, m;

void SCC()
{
	memset(dfn, 0, sizeof(dfn)); /*初始化*/
	memset(instack, 0, sizeof(instack));
	dfsid = 0, sptr = -1;
	int restk[MAX], reit[MAX], resptr = -1; /*模擬遞迴*/
	int v, u, i;
	for (u = 1; u <= n; u++)
	{
		if (!dfn[u])
		{
Inker:
			restk[++resptr] = u;
			dfn[u] = low[u] = ++dfsid;
			instack[u] = true;
			stk[++sptr] = u;
			for (i = 0; i < edge[u].size(); i++)
			{
				v = edge[u][i];
				if (!dfn[v])
				{
					reit[resptr] = i; /*模擬遞迴往下遞*/
					u = v;
					goto Inker;
				}
Kuo:
				if(instack[v])
					low[u] = min(low[u], low[v]);
			}
			if(dfn[u] == low[u]) /*縮點*/
			{
				do
				{
					instack[stk[sptr]] = false;
					contract[stk[sptr]] = u;
				} while (sptr >= 0 && stk[sptr--] != u);
			}
			v = u; /*模擬遞迴 return 實作*/
			resptr--;
			if (resptr < 0) continue;
			i = reit[resptr];
			u = restk[resptr];
			goto Kuo;
		}
	}
	return;
}

int indeg[MAX], ans;

void sol() /*計算多少點 indegree 為零*/
{
	int i, u, v;
	memset(indeg, 0, sizeof(indeg));
	ans = 0;
	for (u = 1; u <= n; u++)
	{
		for (i = 0; i < edge[u].size(); i++)
		{
			v = edge[u][i];
			if (contract[u] != v) /*縮起來不是縮點就戳*/
				indeg[v]++;
			if (contract[u] != contract[v]) /*縮起來不同點就戳*/
				indeg[contract[v]]++;
		}
	}
	for (u = 1; u <= n; u++)
		if (!indeg[u])
			ans++;
	return;
}

void getd(int &d) /*輸入優化*/
{
	char ch;
	while (!isdigit(ch = getchar())) ;
	d = 0;
	do
	{
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
	return;
}

int main()
{
	int t, i, a, b;
	for (getd(t); t; t--)
	{
		getd(n), getd(m);
		for (i = 1; i <= n; i++) edge[i].clear();
		for (i = 0; i < m; i++)
		{
			getd(a), getd(b);
			edge[a].push_back(b);
		}
		SCC();
		sol();
		printf("%d\n", ans);
	}
}