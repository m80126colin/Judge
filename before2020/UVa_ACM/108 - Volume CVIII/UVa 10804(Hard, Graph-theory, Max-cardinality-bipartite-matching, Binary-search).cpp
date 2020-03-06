/**
 *  @judge UVa
 *  @id 10804
 *  @tag Hard, Graph theory, Max cardinality bipartite matching, Binary search
 */
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX 110
#define EPS 5.14e-7
int n, m;
int N[MAX], M[MAX];
bool visited[MAX];
double r[MAX][MAX], ans;

int DFS(int i, double lim)
{
	int j;
	for (j = 0; j < m; j++)
	{
		if (!visited[j] && r[i][j] < lim - EPS)
		{
			visited[j] = 1;
			if (M[j] == -1 || DFS(M[j], lim))
			{
				N[i] = j;
				M[j] = i;
				return 1;
			}
		}
	}
	return 0;
}

int match(double lim)
{
	int i, sum = 0;
	memset(N, -1, sizeof(N));
	memset(M, -1, sizeof(M));
	for (i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		if (DFS(i, lim)) sum++;
	}
	return sum;
}

struct point
{
	double x, y;
}gopher[MAX], hole[MAX];
int k;

double dis(point a, point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int sol(double mx)
{
	double right, left, middle;
	left = 0.0;
	right = mx;
	if (match(right) < n - k) return 0;
	while (right > left + EPS)
	{
		middle = (left + right) / 2.0;
		if (match(middle) < n - k) left = middle;
		else right = middle;
	}
	ans = left;
	return 1;
}

int main()
{
	int i, j, t, cnt;
	double mx;
	for (scanf("%d", &t), cnt = 1; cnt <= t; cnt++)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (i = 0; i < n; i++)
			scanf("%lf%lf", &gopher[i].x, &gopher[i].y);
		for (j = 0; j < m; j++)
			scanf("%lf%lf", &hole[j].x, &hole[j].y);
		mx = 0.0;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				r[i][j] = dis(gopher[i], hole[j]);
				mx = max(mx, r[i][j]);
			}
		printf("Case #%d:\n", cnt);
		if (sol(mx)) printf("%.3lf\n", ans);
		else puts("Too bad.");
		puts("");
	}
}