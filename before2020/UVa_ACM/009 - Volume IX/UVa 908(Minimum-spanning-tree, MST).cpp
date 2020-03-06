/**
 *  @judge UVa
 *  @id 908
 *  @tag Minimum Spanning Tree
 */
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define M 1000000
using namespace std;

struct edge
{
	int a, b, c;
	edge() {};
	edge(int a, int b, int c): a(a), b(b), c(c) {};
};
int p[M];
int n, m, k;
vector <edge> E;

inline int find(int x)
{
	return (x == p[x]) ? x: (p[x] = find(p[x]));
}

inline void uniset(int a, int b)
{
	p[find(a)] = find(b);
	return;
}

inline int kruskal()
{
	int i, j, ans = 0;
	for (i = 0; i < n; i++) p[i] = i;
	for (i = 0, j = 1; i < E.size() && j < n; i++)
	{
		if (find(E[i].a) != find(E[i].b))
		{
			uniset(E[i].a, E[i].b);
			ans += E[i].c;
			j++;
		}
	}
	return ans;
}

bool cmp(edge left, edge right)
{
	return left.c < right.c;
}

int main()
{
	int i, h1, h2, w1, sum;
	int ctr = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (ctr) puts("");
		E.clear();
		for (i = 1, sum = 0; i < n; i++)
		{
			scanf("%d%d%d", &h1, &h2, &w1);
			E.push_back(edge(h1 - 1, h2 - 1, w1));
			sum += w1;
		}
		scanf("%d", &k);
		for (i = 0; i < k; i++)
		{
			scanf("%d%d%d", &h1, &h2, &w1);
			E.push_back(edge(h1 - 1, h2 - 1, w1));
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &h1, &h2, &w1);
			E.push_back(edge(h1 - 1, h2 - 1, w1));
		}
		sort(E.begin(), E.end(), cmp);
		printf("%d\n%d\n", sum, kruskal());
		ctr++;
	}
}