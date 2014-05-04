#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

struct circle
{
	int x, y, r;
	circle() { x = y = r = 0; }
	circle(int x, int y, int r): x(x), y(y), r(r) {}
};
#define MAX 20
int n;
circle C[MAX];
int edge[MAX][MAX];

int test(int i, int j)
{
	return sqrt((double) (C[i].x - C[j].x) * (C[i].x - C[j].x) + (C[i].y - C[j].y) * (C[i].y - C[j].y)) > (C[i].r + C[j].r);
}

int sol(int x)
{
	int i, j;
	vector <int> T;
	T.clear();
	for (i = 0; x; i++)
	{
		if (x & 1) T.push_back(i);
		x >>= 1;
	}
	for (i = 0; i < T.size(); i++)
		for (j = i + 1; j < T.size(); j++)
			if (!edge[T[i]][T[j]]) return 0;
	return 1;
}

long long area(int x)
{
	int i;
	long long sol = 0;
	for (i = 0; x; i++)
	{
		if (x & 1) sol += C[i].r * C[i].r;
		x >>= 1;
	}
	return sol;
}

int main()
{
	long long ans;
	int t, i, j, a, b, c;
	for (scanf("%d", &t); t; t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			C[i] = circle(a, b, c);
		}
		memset(edge, 0, sizeof(edge));
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (test(i, j)) edge[i][j] = edge[j][i] = 1;
		ans = 0;
		for (i = 1; i < (1 << n); i++)
			if (sol(i)) ans = max(ans, area(i));
		printf("%lld\n", ans);
	}
}