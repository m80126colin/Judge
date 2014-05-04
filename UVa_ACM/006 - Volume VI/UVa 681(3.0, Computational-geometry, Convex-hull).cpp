#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

#define EPS 5.14e-8
#define zero(x) ((-EPS < x) && (x < EPS))
#define sign(x) ((EPS < x)?1:((x < -EPS)?-1:0))
#define myabs(x) ((sign(x) > 0)? (x): -(x))

struct point
{
	int x, y;
	point() { x = y = 0; }
	point(int x, int y): x(x), y(y){}
	bool operator < (const point& b) const
	{
		if (y != b.y) return y < b.y;
		return x < b.x;
	}
	point operator + (const point& b)
	{
		return point(x + b.x, y + b.y);
	}
	point operator - (const point& b)
	{
		return point(x - b.x, y - b.y);
	}
};

int dot(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}
int cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}

#define MAXN 550
int k, n, c;
point poly[MAXN], convex[MAXN];

int main()
{
	int i, tmp;
	scanf("%d", &k);
	for (printf("%d\n", k); k; k--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d%d", &poly[i].x, &poly[i].y);
		if (k > 1) scanf("%d", &tmp);
		sort(poly, poly + n);
		for (i = c = 0; i < n; i++)
		{
			while (c >= 2 && cross(convex[c - 1] - convex[c - 2], poly[i] - convex[c - 1]) <= 0) c--;
			convex[c++] = poly[i];
		}
		for (tmp = c + 1, i = n - 2; i >= 0; i--)
		{
			while (c >= tmp && cross(convex[c - 1] - convex[c - 2], poly[i] - convex[c - 1]) <= 0) c--;
			convex[c++] = poly[i];
		}
		printf("%d\n", c);
		for (i = 0; i < c; i++)
			printf("%d %d\n", convex[i].x, convex[i].y);
		if (k > 1)puts("-1");
	}
}