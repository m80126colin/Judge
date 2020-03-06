/**
 *  @judge NTUJ
 *  @id 1666
 *  @tag Disjoint Set, Graph theory, Euler tour
 */
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000010
int n, m, cnt, com, ne, v;
int g[MAX], card[MAX], deg[MAX], hash[MAX];
vector<int> clist;

int Find(int x)
{
	if (x != g[x])
		return g[x] = Find(g[x]);
	return x;
}

void Union(int s, int t)
{
	int a = Find(s), b = Find(t);
	if (card[a] > card[b])
	{
		g[b] = a;
		card[a] += card[b];
	}
	else
	{
		g[a] = b;
		card[b] += card[a];
	}
	return ;
}

int main()
{
	int i, j;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		memset(deg, 0, sizeof(deg));
		for (i = 1; i <= n; i++) g[i] = i, card[i] = 1;
		for (i = 0; i < m; i++)
		{
			int s, t;
			scanf("%d%d", &s, &t);
			if (s != t && Find(s) != Find(t)) Union(s, t);
			deg[s]++;
			deg[t]++;
		}
		memset(hash, 255, sizeof(hash));
		clist.clear();
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			j = Find(i);
			if (deg[j] && hash[j] < 0)
			{
				clist.push_back(0);
				hash[j] = cnt++;
			}
			if (deg[i] & 1) clist[hash[j]]++;
		}
		if (hash[Find(1)] < 0) clist.push_back(0);
		ne = v = 0;
		com = clist.size();
		for (i = 0; i < clist.size(); i++)
		{
			v += clist[i];
			if (clist[i]) ne++;
		}
		printf("%d\n", (com > 1)?((v - 2 * ne) / 2 + com):(v / 2));
	}
}