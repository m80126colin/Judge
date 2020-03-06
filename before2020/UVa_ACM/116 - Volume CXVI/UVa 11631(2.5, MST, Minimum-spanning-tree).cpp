/**
 *  @judge UVa
 *  @id 11631
 *  @tag 2.5, Minimum Spanning Tree
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m, n;
int ans, tot;
struct edge
{
	int from, to, w;
	edge(){}
	edge(int a, int b, int we){
		from = a;
		to = b;
		w = we;
	}
	bool operator < (const edge &V) const
	{
		if (w != V.w) return w < V.w;
		return from < V.from;
	}
};
#define MAXM 200010
vector<edge> E;

int input()
{
	int i, a, b, w;
	if (scanf("%d%d", &m, &n) == EOF)
		return EOF;
	if (m == 0 && n == 0) return EOF;
	E.clear();
	tot = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d%d%d", &a, &b, &w);
		if (a > b) swap(a, b);
		E.push_back( edge(a, b, w) );
		tot += w;
	}
	return 0;
}

int father[MAXM];

int find(int a)
{
	return (father[a] != a)? (father[a] = find(father[a])): a;
}

int MST()
{
	int sol = 0, i, j;
	sort(E.begin(), E.end());
	for (i = 0; i < m; i++)
		father[i] = i;
	for (i = j = 0; j < n && i < m - 1; j++)
	{
		int fa = find(E[j].from), fb = find(E[j].to);
		if (fa != fb)
		{
			father[fa] = fb;
			sol += E[j].w;
			i++;
		}
	}
	return sol;
}

int main()
{
	while (input() != EOF)
	{
		int ans = MST();
		printf("%d\n", tot - ans);
	}
}