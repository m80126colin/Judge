/**
 *  @judge NTUJ
 *  @id 1839
 *  @tag 3.0, Computational geometry, Convex hull
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

#define N 1010
#define EPS 5.14e-8
struct point
{
	double x, y;
};
double dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}
double dot(point a, point b, point o)
{
	return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}
double cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
double cross(point a, point b, point o)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
double dis2(point a, point b)
{
	return dot(a, a, b);
}

int sign(double x)
{
	if (x > EPS) return 1;
	if (x < -EPS) return -1;
	return 0;
}
int sign(double x, double y)
{
	if (x > y + EPS) return 1;
	if (x < y - EPS) return -1;
	return 0;
}
double myabs(double x)
{
	if (x < 0) return -x;
	return x;
}

int cmp(point L, point R)
{
	if (sign(L.x, R.x))
		return L.x < R.x;
	return L.y < R.y;
}

void convexHull(int n, int &m, point *p, point *ch)
{
	int i, t;
	sort(p, p + n, cmp);
	for (i = m = 0; i < n; i++)
	{
		while (m >= 2 && sign(cross(ch[m - 1], p[i], ch[m - 2])) <= 0)
			m--;
		ch[m++] = p[i];
	}
	for (i = n - 2, t = m + 1; i >= 0; i--)
	{
		while (m >= t && sign(cross(ch[m - 1], p[i], ch[m - 2])) <= 0)
			m--;
		ch[m++] = p[i];
	}
	m--;
	return ;
}

double convexArea(int m, point *ch)
{
	double a1 = 0.0, a2 = 0.0;
	for (int i = 0; i < m; i++)
		a1 += ch[i].x * ch[i + 1].y, a2 += ch[i].y * ch[i + 1].x;
	return myabs(a1 - a2) / 2.0;
}

int main()
{
	int n, m;
	point p[N], ch[N];
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
			m = 0;
			convexHull(i + 1, m, p, ch);
			printf("%.1lf\n", convexArea(m, ch));
		}
	}
}