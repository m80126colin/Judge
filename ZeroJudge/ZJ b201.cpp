#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 100010
using namespace std;

int n;
vector <int> adj[MAX];
int dfn[MAX], low[MAX], dfsid;
bool instack[MAX];
int contract[MAX];
stack <int> s;
int cntn[MAX], cntid[MAX];

inline void getd(int &d)
{
	char ch;
	while (!isdigit(ch = getchar()));
	d = 0;
	do
	{
		d = d * 10 + ch - '0';
	} while (isdigit(ch = getchar()));
}

void DFS(int i)
{
	dfn[i] = low[i] = dfsid++;
	instack[i] = true;
	s.push(i);
	for (int j = 0; j < adj[i].size(); j++)
	{
		int u = adj[i][j];
		if (!dfn[u])
			DFS(u);
		if (instack[u])
			low[i] = min(low[i], low[u]);
	}
		if (dfn[i] == low[i])
		{
			while (s.top() != i)
			{
				contract[s.top()] = i;
				instack[s.top()] = false;
				s.pop();
			}
			contract[s.top()] = i;
			instack[s.top()] = false;
			s.pop();
		}
	return;
}

void tarjan()
{
	memset(dfn, 0, sizeof(dfn));
	memset(instack, false, sizeof(instack));
	dfsid = 0;
	while (!s.empty()) s.pop();
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			DFS(i);
	return;
}

int cnt_sort()
{
	int i, j, num = 0;
	memset(cntn, 0, sizeof(cntn));
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j < num; j++)
		{
			if (cntid[j] == contract[i]) {
				cntn[j]++;
				break;
			}
		}
		if (j == num) cntid[num] = contract[i], cntn[num++]++;
	}
	sort(cntn, cntn + num);
	return num;
}

int main()
{
	int m, i, a1, a2;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0; i < n; i++) adj[i].clear();
		for (i = 0; i < m; i++)
		{
			getd(a1);
			getd(a2);
			adj[a1].push_back(a2);
		}
		tarjan();
		a1 = 0;
		a1 = cnt_sort();
		for (i = 0; i < a1; i++)
			printf("%d ", cntn[i]);
		puts("");
	}
}