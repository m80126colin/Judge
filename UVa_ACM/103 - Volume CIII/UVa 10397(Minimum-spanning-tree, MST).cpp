#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#define M 750
using namespace std;

struct node
{
	int x, y;
}V[M];
struct edge
{
	int a, b;
	double len;
	edge() {};
	edge(int a, int b, double len): a(a), b(b), len(len) {};
}E[M * M];
int group[M];
int n, m;

inline int find(int x)
{
	return (x == group[x]) ? x: (group[x] = find(group[x]));
}

inline void uniset(int a, int b)
{
	group[find(a)] = find(b);
	return;
}

inline double kruskal(int k)
{
	int i;
	double ans = 0;
	for (i = 0; k < n; i++)
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

inline double dis(int i, int j)
{
	return sqrt((double) (V[i].x - V[j].x) * (V[i].x - V[j].x) + (V[i].y - V[j].y) * (V[i].y - V[j].y));
}

bool cmp(edge left, edge right)
{
	return left.len < right.len;
}

int main()
{
	int i, j, k, nn;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &V[i].x, &V[i].y);
			group[i] = i;
		}
		scanf("%d", &m);
		for (k = 0, nn = 1; k < m; k++)
		{
			scanf("%d%d", &i, &j);
			i--, j--;
			if (find(i) != find(j))
			{
				uniset(i, j);
				nn++;
			}
		}
		for (i = k = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (find(i) != find(j))
				{
					E[k] = edge(i, j, dis(i, j));
					k++;
				}
		sort(E, E + k, cmp);
		printf("%.2lf\n", kruskal(nn));
	}
}