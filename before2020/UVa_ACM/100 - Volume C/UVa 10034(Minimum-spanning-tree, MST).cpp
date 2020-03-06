/**
 *  @judge UVa
 *  @id 10034
 *  @tag Minimum Spanning Tree
 */
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#define M 100
using namespace std;

struct node
{
	double x, y;
}V[M];
struct edge
{
	int a, b;
	double len;
	edge() {};
	edge(int a, int b, double len): a(a), b(b), len(len) {};
}E[M * M];
int group[M];
int n;

inline double dis(int a, int b)
{
	return sqrt((V[a].x - V[b].x) * (V[a].x - V[b].x) + (V[a].y - V[b].y) * (V[a].y - V[b].y));
}

bool cmp(edge left, edge right)
{
	return left.len < right.len;
}

inline int find(int x)
{
	if (x == group[x]) return x;
	return group[x] = find(group[x]);
}

inline void uniset(int a, int b)
{
	group[find(a)] = find(b);
	return;
}

double kruskal()
{
	int i, k;
	double ans = 0;
	for (i = 0; i < n; i++) group[i] = i;
	for (i = 0, k = 1; k < n; i++)
	{
		if (find(E[i].a) != find(E[i].b))
		{
			uniset(E[i].a, E[i].b);
			ans += E[i].len;
			k++;
		}
	}
	return ans;
}

int main()
{
	int t;
	int i, j, k;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &V[i].x, &V[i].y);
		for (i = k = 0; i < n; i++)
			for (j = i + 1; j < n; j++, k++)
				E[k] = edge(i, j, dis(i, j));
		sort(E, E + k, cmp);
		printf("%.2lf\n", kruskal());
		if (t > 1) puts("");
	}
}