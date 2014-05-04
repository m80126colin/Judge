#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <vector>
#define MAX 130
using namespace std;

int s, a, m;
vector <int> edge[MAX];
/*
for street i, ai = edge[2 * i], ai' = edge[2 * i + 1]
for avenue j, aj = edge[2 * (s + j)], aj' = edge[2 * (s + j) + 1]
*/
int dfn[MAX], low[MAX], dfsid;
stack <int> stk;
int contract[MAX];
bool instack[MAX];

inline void input()
{
	int u1, v1, u2, v2, ox, ox2;
	scanf("%d%d%d%d", &u1, &v1, &u2, &v2);
	u1 = 2 * (u1 - 1), v1 = 2 * (s + v1 - 1);
	u2 = 2 * (u2 - 1), v2 = 2 * (s + v2 - 1);
	if (u1 == u2 && v1 == v2) ;
	else if (u1 == u2)
	{
		ox = v1 < v2;
		edge[u1 + !ox].push_back(u1 + ox); /*u1' --> u1*/
	}
	else if (v1 == v2)
	{
		ox = u1 < u2;
		edge[v1 + !ox].push_back(v1 + ox); /*v1' --> v1*/
	}
	else
	{
		/*
		u1' <--> u2', v1'
		v2' <--> u2', v1'
		*/
		ox = v1 < v2;
		ox2 = u1 < u2;
		edge[u1 + !ox].push_back(u2 + ox); /*u1' --> u2*/
		edge[u1 + !ox].push_back(v1 + ox2); /*u1' --> v1*/
		edge[u2 + !ox].push_back(u1 + ox); /*u2' --> u1*/
		edge[v1 + !ox2].push_back(u1 + ox); /*v1' --> u1*/

		edge[v2 + !ox2].push_back(u2 + ox); /*v2' --> u2*/
		edge[v2 + !ox2].push_back(v1 + ox2); /*v2' --> v1*/
		edge[u2 + !ox].push_back(v2 + ox2); /*u2' --> v2*/
		edge[v1 + !ox2].push_back(v2 + ox2); /*v1' --> v2*/
	}
}

void DFS(int i)
{
	int tmp;
	dfn[i] = low[i] = ++dfsid;
	stk.push(i);
	instack[i] = true;
	for (int j = 0; j < edge[i].size(); j++)
	{
		int u = edge[i][j];
		if (!dfn[u])
			DFS(u);
		if (instack[u])
			low[i] = min(low[i], low[u]);
	}
	if (dfn[i] == low[i])
	{
		do
		{
			tmp = stk.top();
			contract[tmp] = i;
			instack[tmp] = false;
			stk.pop();
		} while (tmp != i);
	}
	return;
}

void tarjan()
{
	dfsid = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(instack, false, sizeof(instack));
	while (!stk.empty()) stk.pop();
	for (int i = 0; i < 2 * (s + a); i++)
		if (!dfn[i])
			DFS(i);
	return;
}

bool sol()
{
	for (int i = 0; i < s + a; i++)
		if (contract[2 * i] == contract[2 * i + 1]) return 0;
	return 1;
}

int main()
{
	int t, i;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d%d%d", &s, &a, &m);
		for (i = 0; i < 2 * (s+a); i++) edge[i].clear();
		for (i = 0; i < m; i++) input();
		tarjan();
		if (sol()) puts("Yes");
		else puts("No");
	}
}